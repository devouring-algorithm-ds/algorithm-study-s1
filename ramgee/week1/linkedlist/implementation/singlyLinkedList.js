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
    return node[0];
  }

  getNode(index) {
    if (!(Number.isSafeInteger(index) && 0 <= index && index < this.length)) {
      return null;
    }

    let node = this.head;
    for (let i = 0; i < index; i++) {
      node = node[1];
    }
    return node;
  }

  insertFront(value) {
    if (this.length === 0) {
      this.head = [value, null];
      this.tail = this.head;
    } else {
      const newHead = [value, this.head];
      this.head = newHead;
    }
    this.length += 1;
  }

  removeFront() {
    if (this.length >= 0) {
      this.head = this.head[1];
      this.length -= 1;
    } else {
      console.log('There is no item.');
    }
  }

  insertBack(value) {
    if (this.length === 0) {
      this.head = [value, null];
      this.tail = this.head;
    } else {
      const newTail = [value, null];
      this.tail[1] = newTail;
      this.tail = newTail;
    }
    this.length += 1;
  }

  removeBack() {
    if (this.length >= 0) {
      const beforeTail = this.getNode(this.length - 1);
      beforeTail[1] = null;
      this.tail = beforeTail;
      this.length -= 1;
    } else {
      console.log('There is no item.');
    }
  }
}

exports.LinkedList = LinkedList;
