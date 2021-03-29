#include "doubly_linkedlist.h"

template <class T>
class ListStack {
    LinkedList<T> list;

public:
    T& peek() {
        // Return top element
        return list.back();
    }

    void pop() {
        // Remove top element
        list.pop_back();
    }

    bool isEmpty() {
        // Return true if empty, false otherwise
      return list.empty();
    }

    int size() {
        // Return number of elements
        return list.size();
    }

    void push(T& item) {
        // Add a new item at the top
      list.push_back(item);
    }

    // You may add other member functions,
    // including constructor and destructor
};
