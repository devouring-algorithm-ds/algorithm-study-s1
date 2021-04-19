/* https://github.com/joonas-yoon/Class-Algorithm/tree/master/Red-Black-Tree */

#pragma once 

#include <iostream> // cout, swap

#include "Node.hpp"

#define NIL 0

#define CASE_AUTO -2
#define CASE_FAIL -1
#define CASE_ROOT  0
#define CASE_1_1   1
#define CASE_2_1   2
#define CASE_2_4   3
#define CASE_X_2   4
#define CASE_X_3   5

class RedBlackTree {
private:
	Node *root;
	Node *nil;

	Node *_insert(Node*, Node*);
	Node *_delete(Node*, bool*);
	Node *_search(Node*, int); // binary search
	Node *_findMaxNode(Node*);

	void _coloringAfterInsert(Node*);
	void _coloringAfterDelete(Node*, int caseNumber = CASE_AUTO);

	int whatCaseOf(Node*);

	Node *_rotateLeft(Node*);
	Node *_rotateRight(Node*);

	bool _isNull(Node*);
	bool _detectDanger(Node*); // 이 노드를 지우려는 경우, 문제가 발생할 수 있는가?

public:
	RedBlackTree() {
		nil = new Node();
		nil->setBlackColor();
		root = nil;
	}
	~RedBlackTree(){
		bool nothing;
		_delete(root, &nothing);
		root = nil = NIL;
	}

	void Insert(int);
	void Delete(int);
	bool Find(int);

	void Print(){ Print(this->root); }
	void Print(Node *n, int d = 0, bool isLeft = true);
  void Inorder();
  void InorderHelper(Node *);

	Node *getRoot() const { return this->root; }
};

void RedBlackTree::Insert(int data){
  // unique; if exists, break.
	if (_isNull(_search(root, data)) == false){
		return;
	}

  // Node(key, left, right)
	Node *newNode = new Node(data, nil, nil);
	if (!root){
		root = newNode;
		root->parent = nil;
	}
	else {
		root = _insert(root, newNode);
		_coloringAfterInsert(newNode);
	}
	root->setBlackColor();
	root->parent = nil;
}

Node* RedBlackTree::_insert(Node *node, Node *newItem){
	if (_isNull(node)){
		node = newItem;
	}
	else if (newItem->getKey() > node->getKey()){
		Node *child = _insert(node->right, newItem);
		node->right = child;
		child->parent = node;
	}
	else {
		Node *child = _insert(node->left, newItem);
		node->left = child;
		child->parent = node;
	}
	return node;
}

void RedBlackTree::_coloringAfterInsert(Node *x){
  // x= 200
	if (_isNull(x) || _isNull(x->parent)) return;

	// 루트이거나 블랙 노드면 문제없다.
	if (x == root || !x->isRed()) return;

	// 레드 노드는 레드인 자식을 가질 수 없다. 
	Node *p = x->parent; // 160
	if (p == root || !p->isRed()) return;

	// 삽입된 현재 노드는 레드, 부모 노드도 레드인 상황

	Node *s = p->getUncle(); // nil
  Node *pp = p->parent; // a
	// CASE 1 (Double Red)
	if (s->isRed()){
		p->setBlackColor();
		s->setBlackColor();
		pp->setRedColor();
		_coloringAfterInsert(pp);
	}
	// CASE 2 (Unbalanced)
	else {
		bool xLeft = x->isLeftNode(); // NIL
    bool pLeft = p->isLeftNode(); // 160

		// CASE 2-1
		// 방향이 엇갈리는 상황 (XOR)
    // NIL (0) ^ 160 != 0 == True
		if (xLeft ^ pLeft){
			if (xLeft)
				_rotateRight(p);
			else 
				_rotateLeft(p);
			_coloringAfterInsert(p);
		}
		// CASE 2-2
		else {
			if (pLeft)
				_rotateRight(pp);
			else
				_rotateLeft(pp);
			p->swapColor(pp);
			_coloringAfterInsert(x);
		}
	}
}

void RedBlackTree::Delete(int data){
	Node *delNode = _search(root, data);
	if (_isNull(delNode)){
		return;
	}
	bool hasProblem = _detectDanger(delNode);
	Node *newMid = _delete(delNode, &hasProblem);
	if (hasProblem){
		_coloringAfterDelete(newMid);
	}
}

Node* RedBlackTree::_delete(Node *node, bool *hasProblem){
	if (_isNull(node)) return nil;

	bool hasLeft = ! _isNull(node->left),
		hasRight = ! _isNull(node->right);

	bool isLeft = node->isLeftNode();

	if (hasLeft && hasRight){
		Node *rightMax = _findMaxNode(node->left);

		Node *newMid = rightMax;
		// 왼쪽 서브트리가 아예 없는 경우
		if (_isNull(rightMax)){
			rightMax = node->right;
		}
		// 왼쪽 서브트리에서 왼쪽 노드만 있는 경우
		else if (rightMax == node->left){
			if (isLeft){
				rightMax->parent = node->parent;
				rightMax->parent->left = rightMax;
			}
			else {
				rightMax->parent = node->parent;
				rightMax->parent->right = rightMax;
			}
			rightMax->right = node->right;

			rightMax->left->parent = rightMax;
			newMid = rightMax->left;
			*hasProblem |= rightMax->isRed() == false;
		}
		else {
			// 가장 오른쪽 노드의 왼쪽 서브트리를 부모와 연결해준다. (삭제를 위해)
			rightMax->parent->right = rightMax->left;
			rightMax->left->parent = rightMax->parent;

			// 지우려는 노드의 자리를 대체
			rightMax->left = node->left;
			rightMax->right = node->right;
		}
		rightMax->parent = node->parent;
		rightMax->right->parent = rightMax->left->parent = rightMax;

		if (node == root){
			root = rightMax;
		}
		else {
			if (isLeft)
				rightMax->parent->left = rightMax;
			else
				rightMax->parent->right = rightMax;
		}
		node->swapColor(rightMax);
		delete node;
		return newMid;
	}
	else if (hasLeft && hasRight == false){
		Node *cur = node;
		cur = cur->left;
		cur->parent = node->parent;
		if (node == root){
			root = cur;
			root->parent = nil;
		}
		else {
			if (isLeft) cur->parent->left = cur;
			else cur->parent->right = cur;
		}

		// 유일한 자식노드가 레드라면 문제되지 않는다.
		*hasProblem &= cur->isRed() == false;
		node->swapColor(cur);
		delete node;

		cur->right->parent = cur;
		return cur->right;
	}
	else if (hasLeft == false && hasRight){
		Node *cur = node;
		cur = cur->right;
		cur->parent = node->parent;
		if (node == root){
			root = cur;
			root->parent = nil;
		}
		else {
			if (isLeft) cur->parent->left = cur;
			else cur->parent->right = cur;
		}

		// 유일한 자식노드가 레드라면 문제되지 않는다.
		*hasProblem &= cur->isRed() == false;
		node->swapColor(cur);
		delete node;

		cur->left->parent = cur;
		return cur->left;
	}
	else {
		Node *p = node->parent, *ret = nil;
		if (node == root) root = nil;
		else if (isLeft){
			p->left = ret;
			p->left->parent = p;
		}
		else {
			p->right = ret;
			p->right->parent = p;
		}
		delete node;

		return ret;
	}
}

void RedBlackTree::_coloringAfterDelete(Node *x, int caseNumber){
	if (caseNumber == CASE_AUTO)
		caseNumber = whatCaseOf(x);

	// 블랙 노드가 아닌 레드 노드가 입력에 들어온다면
	if (x->isRed()){
		// 자기 앞에 블랙이 빠진거므로 자신을 레드로 바꾼다.
		x->setBlackColor();
		return;
	}

	bool isLeft = x->isLeftNode();

	Node *p = x->parent, *s = x->getUncle();
	Node *l = nil, *r = nil;
	if (_isNull(p)) s = nil;
	if (_isNull(s) == false){
		if (isLeft){
			l = s->left;
			r = s->right;
		}
		else {
			l = s->right;
			r = s->left;
		}
	}

	switch (caseNumber){
	case CASE_1_1:
		p->swapColor(s);
		break;
	case CASE_X_2:
		isLeft ? _rotateLeft(p) : _rotateRight(p);
		p->swapColor(s);
		r->setBlackColor();
		break;
	case CASE_X_3:
		isLeft ? _rotateRight(s) : _rotateLeft(s);
		s->swapColor(l);
		x->parent = p;
		_coloringAfterDelete(x, CASE_X_2);
		break;
	case CASE_2_1:
		s->setRedColor();
		_coloringAfterDelete(p);
		break;
	case CASE_2_4:
		isLeft ? _rotateLeft(p) : _rotateRight(p);
		p->swapColor(s);
		// CASE 1-1, 1-2, 1-3 중 하나로..
		_coloringAfterDelete(x);
		break;
	case CASE_ROOT:
		if (_isNull(x->left)){
			x->left->parent = x;
			_coloringAfterDelete(x->left);
		}
		else {
			x->right->parent = x;
			_coloringAfterDelete(x->right);
		}
		break;
	case CASE_FAIL:
		break;
	}
}

bool RedBlackTree::Find(int data){
	Node *node = _search(this->root, data);
	return _isNull(node) == false;
}

Node* RedBlackTree::_search(Node *node, int data){
	if (_isNull(node)) return nil;

	int key = node->key;
	if (key == data) return node;
	else if (key < data) return _search(node->right, data);
	else return _search(node->left, data);
}

Node* RedBlackTree::_findMaxNode(Node *node) {
	if (_isNull(node->right))
		return node;
	return _findMaxNode(node->right);
}

int RedBlackTree::whatCaseOf(Node *nodeX){
	bool isParentRed = false; // p
	bool isUncleRed = false; // s
	bool isCousinCloseRed = false; // x가 왼쪽일 때 기준, l
	bool isCousinFarRed = false; // x가 왼쪽일 때 기준, r

	Node *p = nodeX->parent;
	if (_isNull(p) == false){
		isParentRed |= p->isRed();
		Node *s = nodeX->getUncle();
		if (_isNull(s) == false){
			isUncleRed |= s->isRed();

			// 우선, x가 왼쪽일 때 기준으로 상태를 설정
			isCousinCloseRed |= _isNull(s->left) == false && s->left->isRed();
			isCousinFarRed |= _isNull(s->right) == false && s->right->isRed();

			// 좌우 반전인 경우에 대한 처리
			if (s->isLeftNode()){
				std::swap(isCousinCloseRed, isCousinFarRed);
			}
		}
		else {
			isUncleRed = true; // leaf is black
		}
	}
	else {
		return CASE_ROOT;
	}

	if (isParentRed && !isUncleRed){
		// CASE 1:
		// p가 레드(s는 반드시 블랙), <l의 색상, r의 색상>에 따라
		if (isCousinFarRed) return CASE_X_2;
		if (isCousinCloseRed) return CASE_X_3;
		return CASE_1_1;
	}
	else if (!isParentRed){
		// CASE 2:
		// p가 블랙 <s의 색상, l의 색상, r의 색상>에 따라
		if (isUncleRed){
			if (isCousinCloseRed || isCousinFarRed) return CASE_FAIL;
			// s가 레드이면 l과 r은 반드시 블랙이어야 한다.
			return CASE_2_4;
		}
		if (isCousinFarRed) return CASE_X_2;
		if (isCousinCloseRed) return CASE_X_3;
		return CASE_2_1;
	}

	return CASE_FAIL;
}

bool RedBlackTree::_detectDanger(Node *x){
	if (_isNull(x)) return false;

	// 삭제 노드가 레드이면 문제 없다.
	if (x->isRed()) return false;

	// 노드 x가 루트이면 문제가 없음
	Node *p = x->parent;
	if (x == root || _isNull(p)) return false;

	bool hasLeft = _isNull(x->left),
		hasRight = _isNull(x->right);

	// 삭제 노드가 블랙이더라도, 자식이 없으면 상관 없다.
	if (!hasLeft && !hasRight) return false;

	bool hasBlackChild = false;
	if (hasLeft){
		hasBlackChild |= x->left->isRed() == false;
	}
	if (hasRight){
		hasBlackChild |= x->right->isRed() == false;
	}

	// 블랙인 자식이 하나라도 있다면 문제가 생긴다.
	return hasBlackChild;
}

Node* RedBlackTree::_rotateRight(Node *x){
	if (_isNull(x)) return x;
	Node *l = x->left, *p = x->parent;

	bool isLeft = x->isLeftNode();

	x->left = l->right;
	x->left->parent = x;
	l->right = x;
	l->right->parent = l;

	// (부모/자식 관계를 갱신)
	// 돌리려는 중심이 루트였다면 루트를 변경
	if (x == root){
		root = l;
		root->parent = nil;
	}
	else {
		l->parent = p;
		if (isLeft) p->left = l;
		else p->right = l;
	}

	// 새로운 중심을 반환한다.
	return l;
}

Node* RedBlackTree::_rotateLeft(Node *x){
	if (_isNull(x)) return x;
	Node *r = x->right, *p = x->parent;

	bool isLeft = x->isLeftNode();

	x->right = r->left;
	x->right->parent = x;
	r->left = x;
	r->left->parent = r;

	if (x == root){
		root = r;
		root->parent = nil;
	}
	else {
		r->parent = p;
		if (isLeft) p->left = r;
		else p->right = r;
	}

	// 새로운 중심을 반환한다.
	return r;
}

void RedBlackTree::Print(Node *n, int dep, bool isLeft){
	if (_isNull(n)) return;
	for (int i = 0; i < dep; ++i) std::cout<< "    ";
	std::cout << n->key << (n->isRed() ? "[R]" : "[B]") << '\n';
	Print(n->left, dep + 1);
	Print(n->right, dep + 1, false);
}

bool RedBlackTree::_isNull(Node *x){
	return x == NIL || x == nil;
}

void RedBlackTree::Inorder() {
  InorderHelper(root);
  std::cout << std::endl;
}

void RedBlackTree::InorderHelper(Node *node) {
  if( node==nullptr ) return;

  InorderHelper(node->left);
  if (node->key != NIL) 
    std::cout << node->key << ' ';
  InorderHelper(node->right);
}
