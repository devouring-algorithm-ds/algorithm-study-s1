const { Node } = require('./node');

class LinkedList {
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
    return node.value;
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

  insertFront(value) {
    if (this.length === 0) {
      this.head = new Node(value, null);
      this.tail = this.head;
    } else {
      const newHead = new Node(value, this.head);
      this.head = newHead;
    }
    this.length += 1;
  }

  removeFront() {
    if (this.length > 0) {
      this.head = this.head.next;
      this.length -= 1;
    } else {
      console.log('There is no item.');
    }
  }

  insertBack(value) {
    if (this.length === 0) {
      this.head = new Node(value, null);
      this.tail = this.head;
    } else {
      const newTail = new Node(value, null);
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
      const beforeTail = this.getNode(this.length - 2);
      beforeTail.next = null;
      this.tail = beforeTail;
      this.length -= 1;
    }
  }
}

exports.LinkedList = LinkedList;
