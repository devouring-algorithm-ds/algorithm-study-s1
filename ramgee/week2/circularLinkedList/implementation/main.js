const { CircularLinkedList } = require('./CircularLinkedList');

class Main {
  static main() {
    const cll = new CircularLinkedList();

    console.log('\nAdd 3 numbers in the front');
    cll.insertFront(345);
    cll.insertFront(-32452);
    cll.insertFront(5);

    console.log(cll.get(0));
    console.log(cll.get(1));
    console.log(cll.get(2));

    console.log('\nRemove items from the front');
    cll.removeFront();
    console.log(cll.get(0));

    cll.removeFront();
    console.log(cll.get(0));

    console.log('\nAdd 3 numbers in the back');
    cll.insertBack(455);
    cll.insertBack(10);
    cll.insertBack(41);

    console.log('\nCheck items');
    console.log(cll.get(0));
    console.log(cll.get(1));
    console.log(cll.get(2));
    console.log(cll.get(3));

    console.log('\nRemove items from the back');
    cll.removeBack();
    cll.removeBack();
    console.log(cll.get(0));
    console.log(cll.get(1));
    console.log(cll.get(2));
    console.log(cll.get(3));

    console.log("\nRemove items that doesn't exist");
    cll.removeFront();
    cll.removeFront();
    console.log(cll.get(0));
    console.log(cll.get(1));
    console.log(cll.get(2));
    console.log(cll.get(3));
    // console.log(cll);
  }
}

Main.main();
