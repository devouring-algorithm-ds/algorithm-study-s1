const { Node } = require('./node');

class DoublyLinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
    this.length = 0;
  }

  get(index) {
    const node = this.getNode(index);
    if (!node) {
      return null;
    }
    return node.data;
  }

  getNode(index) {
    if (!(Number.isSafeInteger(index) && 0 <= index && index < this.length)) {
      return null;
    }

    let node = this.head;
    for (let i = 0; i < index; i++) {
      node = node.next;
    }
    return node;
  }

  insertFront(data) {
    if (this.length === 0) {
      this.head = new Node(null, data, null);
      this.tail = this.head;
    } else {
      const newHead = new Node(null, data, this.head);
      this.head = newHead;
    }
    this.length += 1;
  }

  removeFront() {
    if (this.length === 0) {
      console.log('There is no item.');
    } else if (this.length === 1) {
      this.head = null;
      this.tail = null;
      this.length = 0;
    } else {
      this.head = this.head.next;
      this.head.prev = null;
      this.length -= 1;
    }
  }

  insertBack(data) {
    if (this.length === 0) {
      this.head = new Node(null, data, null);
      this.tail = this.head;
    } else {
      const newTail = new Node(this.tail, data, null);
      this.tail.next = newTail;
      this.tail = newTail;
    }
    this.length += 1;
  }

  removeBack() {
    if (this.length === 0) {
      console.log('There is no item.');
    } else if (this.length === 1) {
      this.head = null;
      this.tail = null;
      this.length = 0;
    } else {
      const temp = this.tail.prev;
      temp.next = null;
      this.tail = temp;
      this.length -= 1;
    }
  }
}

exports.DoublyLinkedList = DoublyLinkedList;
