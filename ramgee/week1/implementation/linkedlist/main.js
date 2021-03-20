const { LinkedList } = require('./singlyLinkedList');

class Main {
  static main() {
    const sll = new LinkedList();

    console.log('\nAdd 3 numbers in the front');
    sll.insertFront(345);
    sll.insertFront(-32452);
    sll.insertFront(5);

    console.log('\nRemove items from the front');
    sll.removeFront();
    console.log(sll.get(0));

    sll.removeFront();
    console.log(sll.get(0));

    console.log('\nAdd 3 numbers in the back');
    sll.insertBack(455);
    sll.insertBack(10);
    sll.insertBack(41);

    console.log('\nCheck items');
    console.log(sll.get(0));
    console.log(sll.get(1));
    console.log(sll.get(2));
    console.log(sll.get(3));

    console.log('\nRemove items from the back');
    sll.removeBack();
    sll.removeBack();
    console.log(sll.get(0));
    console.log(sll.get(1));
    console.log(sll.get(2));
    console.log(sll.get(3));

    console.log("\nRemove items that doesn't exist");
    sll.removeFront();
    sll.removeFront();
    console.log(sll.get(0));
    console.log(sll.get(1));
    console.log(sll.get(2));
    console.log(sll.get(3));
    console.log(sll);
  }
}

Main.main();
