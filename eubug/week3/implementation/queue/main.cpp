#include "queue.hpp"

int main()
{
  //////////////////////////////////// queue<int>
  Queue<int> *queue = new Queue<int>();

  cout << "Push 1, 2, and 3" << endl;
  queue->enqueue(1);
  queue->enqueue(2);
  queue->enqueue(3);
  queue->print();
  cout << endl;

  cout << "Dequeue..." << endl;
  queue->dequeue();
  queue->print();
  cout << endl;

  cout << "Dequeue..." << endl;
  queue->dequeue();
  queue->print();
  cout << endl;

  cout << "Dequeue..." << endl;
  queue->dequeue();
  queue->print();
  cout << endl;

  cout << "Push 100 and 200" << endl;
  queue->enqueue(100);
  queue->enqueue(200);
  cout << "Dequeue..." << endl;
  queue->dequeue();
  queue->print();
  cout << endl;

  cout << "Push 500" << endl;
  queue->enqueue(500);
  queue->print();
  cout << endl;

  delete queue;

  //////////////////////////////////// queue<char>
  cout << endl << "New Queue!!" << endl;
  Queue<char> *queue2 = new Queue<char>();
  cout << "Push 'a', 'b', and 'c'" << endl;
  queue2->enqueue('a');
  queue2->enqueue('b');
  queue2->enqueue('c');
  queue2->print();

  cout << "Dequeue..." << endl;
  queue2->dequeue();
  queue2->print();

  cout << "Dequeue..." << endl;
  queue2->dequeue();
  queue2->print();

  cout << "Dequeue..." << endl;
  queue2->dequeue();
  queue2->print();

  cout << "Push 'Eubug'" << endl;
  queue2->enqueue('E');
  queue2->enqueue('u');
  queue2->enqueue('b');
  queue2->enqueue('u');
  queue2->enqueue('g');
  queue2->print();
  delete queue2;

  return 0;
}
