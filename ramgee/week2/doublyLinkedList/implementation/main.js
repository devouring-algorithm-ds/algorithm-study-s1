const { DoublyLinkedList } = require('./doublyLinkedList');

class Main {
  static main() {
    const dll = new DoublyLinkedList();

    console.log('\nAdd 3 numbers in the front');
    dll.insertFront(345);
    dll.insertFront(-32452);
    dll.insertFront(5);

    console.log(dll.get(0));
    console.log(dll.get(1));
    console.log(dll.get(2));

    console.log('\nRemove items from the front');
    dll.removeFront();
    console.log(dll.get(0));

    dll.removeFront();
    console.log(dll.get(0));

    console.log('\nAdd 3 numbers in the back');
    dll.insertBack(455);
    dll.insertBack(10);
    dll.insertBack(41);

    console.log('\nCheck items');
    console.log(dll.get(0));
    console.log(dll.get(1));
    console.log(dll.get(2));
    console.log(dll.get(3));

    console.log('\nRemove items from the back');
    dll.removeBack();
    dll.removeBack();
    console.log(dll.get(0));
    console.log(dll.get(1));
    console.log(dll.get(2));
    console.log(dll.get(3));

    console.log("\nRemove items that doesn't exist");
    dll.removeFront();
    dll.removeFront();
    console.log(dll.get(0));
    console.log(dll.get(1));
    console.log(dll.get(2));
    console.log(dll.get(3));
    // console.log(dll);
  }
}

Main.main();
