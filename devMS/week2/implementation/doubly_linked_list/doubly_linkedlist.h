#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H

template <typename T>
class Node {

public:
    Node<T>* prev;
    Node<T>* next;
    T data;

    Node(T val = T()) {
        prev = nullptr;
        next = nullptr;
        data = val;
    }
};

template <class T>
class LinkedList {
    // Dummy nodes
    Node<T>* head;
    Node<T>* tail;

    // member variables
    int sizeVal;
    Node<T>* newNode;
    Node<T>* searchNode;
    Node<T>* frontNode;
    Node<T>* backNode;

public:
    LinkedList() {
        // Constructor.
        head = new Node<T>;
        tail = new Node<T>;

        head->prev = nullptr;
        head->next = tail;

        tail->prev = head;
        tail->next = nullptr;

        sizeVal = 0;

        newNode = nullptr;
        searchNode = nullptr;
        frontNode = nullptr;
        backNode = nullptr;
    }

    ~LinkedList() {
        // Destructor.
        clear();
        delete head;
        delete tail;

    }


    int size() {
        // Return the number of elements in list.
        return sizeVal;
    }

    bool empty() {
        // Return true if no elements are in list and false otherwise.
        if (size() == 0)
            return true;
        else
            return false;
    }

    T& front() {
        // Return the front (first) element.
        // return type is REFERENCE (not value) of the data (not Node).
        frontNode = head->next;
        return (frontNode->data);
    }

    T& back() {
        // Return the back (last) element.
        backNode = tail->prev;
        return (backNode->data);
    }

    void insert(Node<T>* node_before, T val) {
        // Create a node with val. Insert it after node_before.
        // i.e. node_before -> new node -> (node_before->next)

        newNode = new Node<T>;
        newNode->data = val;

        newNode->prev = node_before;
        newNode->next = node_before->next;
        node_before->next->prev = newNode;
        node_before->next = newNode;

        sizeVal += 1;
    }

    void erase(Node<T>* target) {
        // Remove target node from the list.

        if (size() == 0)
        {
            std::cout << "Can't Remove: List is empty" << std::endl;
            return;
        }

        target->next->prev = target->prev;
        target->prev->next = target->next;
        delete target;

        sizeVal -= 1;
    }

    void push_front(T val) {
        // Create a node with val. Add it to the front of the list.
        insert(head, val);
    }

    void pop_front() {
        // Remove the front node.
        frontNode = head->next;
        erase(frontNode);
    }

    void push_back(T val) {
        // Create a node with val. Add it to the back of the list.
        backNode = tail->prev;
        insert(backNode, val);
    }

    void pop_back() {
        // Remove the back node.
        backNode = tail->prev;
        erase(backNode);
    }

    void clear() {
        // Remove all nodes in list.
        for (int i = 0; i < sizeVal; i++)
        {
            pop_front();
        }
    }

    //For Debug
    Node<T>* find(T val) {
        // Return the pointer of first node with the data val.
        searchNode = head;
        for (int i = 0; i < sizeVal; i++)
        {
            searchNode = (searchNode->next);
            if ((searchNode->data) == val)
                return searchNode;
        }
        return nullptr;
    }

    
};
#endif