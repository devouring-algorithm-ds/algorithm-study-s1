/*
 * 요세푸스 문제 (실버V)
 * https://www.acmicpc.net/problem/1158
 * */

#include <iostream>
#include <vector>

using namespace std;

#define ios cin.tie(NULL), ios_base::sync_with_stdio(false)
#define endl '\n'

class Node 
{
  private:
  public:
    int data;
    Node *next;
    Node *prev;
    bool visited;

    Node(int value) : data(value), next(nullptr), prev(nullptr), visited(false) {}
};

class CDlist 
{
  private:
    Node *head;
    Node *tail;
    int length;

  public:
    CDlist();
    ~CDlist();

    void insertBack(int val);
    int get(int start, int pos);
};

CDlist::CDlist() 
{
  head = nullptr;
  tail = nullptr;
  length = 0;
}

CDlist::~CDlist() 
{
  for(int i=0; i<length; ++i)
  {
    Node *temp = head->next;
    delete head;
    head = temp;
  }
}

void CDlist::insertBack(int val) 
{
  Node *newNode = new Node(val);

  if(length == 0) 
  {
    head = newNode;
    tail = newNode;
    head->prev = head->next = tail;
    tail->prev = tail->next = head;
  }
  else 
  {
    tail->next = newNode;
    newNode->next = head;
    head->prev = newNode;
    newNode->prev = tail;
    tail = newNode;
  }

  ++length;
}

int CDlist::get(int start, int position) 
{
  Node *temp = head;
  for(int i=0; i<start; ++i) temp = temp->next;

    while(temp->visited)
      temp = temp->next;
  for(int i=0; i<position; ++i)
  {
    temp = temp->next;
    while(temp->visited)
      temp = temp->next;
  }

  temp->visited = true;
  return temp->data;
}

int main() {
  CDlist list;
  vector<int> vec;
  int n, k;
  cin >> n >> k;
  for(int i=1; i<=n; ++i) list.insertBack(i);

  int start = 0;
  for(int i=0; i<n; ++i) {
    start = list.get(start, k-1);
    vec.push_back(start);
  }

  cout << "<";
  for(int i=0; i<n-1; ++i)
    cout << vec[i] << ", ";
  cout << vec[n-1] << ">" << endl;
  return 0;
}
