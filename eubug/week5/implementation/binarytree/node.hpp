class Node {
  private: 
  public: 
    char data;
    int count; // for duplicates
    Node *left;
    Node *right;

    Node(char _data) : data(_data), count(1), left(nullptr), right(nullptr) {}
};
