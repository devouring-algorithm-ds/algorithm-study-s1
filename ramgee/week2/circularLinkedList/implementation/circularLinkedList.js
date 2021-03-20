const { Node } = require('./node');

class CircularLinkedList {
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
      const temp = new Node(null, data, null);
      temp.prev = temp;
      temp.next = temp;
      this.head = temp;
      this.tail = temp;
    } else {
      const temp = new Node(this.tail, data, this.head);
      this.head.prev = temp;
      this.tail.next = temp;
      this.head = temp;
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
      this.head.prev = this.tail;
      this.tail.next = this.head;
      this.length -= 1;
    }
  }

  insertBack(data) {
    if (this.length === 0) {
      const temp = new Node(null, data, null);
      temp.prev = temp;
      temp.next = temp;
      this.head = temp;
      this.tail = temp;
    } else {
      const temp = new Node(this.tail, data, this.head);
      this.head.prev = temp;
      this.tail.next = temp;
      this.tail = temp;
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
      this.tail = this.tail.prev;
      this.head.prev = this.tail;
      this.tail.next = this.head;
      this.length -= 1;
    }
  }
}

exports.CircularLinkedList = CircularLinkedList;
