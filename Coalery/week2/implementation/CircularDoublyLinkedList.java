
public class CircularDoublyLinkedList<T> {
	protected Node<T> head;
	protected int length;
	
	boolean isEmpty() { return length <= 0; }
	
	void insertFront(T data) {
		Node<T> newNode = new Node<>(data);
		
		if(head == null) {
			head = newNode;
			newNode.nextNode = newNode;
			newNode.prevNode = newNode;
		} else {
			Node<T> tail = head.prevNode;
			newNode.prevNode = tail;
			newNode.nextNode = head;
			head.prevNode = newNode;
			tail.nextNode = newNode;
			head = newNode;
		}
		length++;
	}
	
	void insertBack(T data) {
		Node<T> newNode = new Node<>(data);
		
		if(head == null) {
			head = newNode;
		} else {
			Node<T> tail = head.prevNode;
			head.prevNode = newNode;
			tail.nextNode = newNode;
			newNode.prevNode = tail;
			newNode.nextNode = head;
		}
		length++;
	}
	
	T removeFront() {
		if(head == null) {
			return null;
		}
		
		T data = head.data;
		if(length == 1) {
			head = null;
		} else {
			Node<T> tail = head.prevNode;
			Node<T> newHead = head.nextNode;
			tail.nextNode = newHead;
			newHead.prevNode = tail;
			head = newHead;
		}
		
		length--;
		return data;
	}
	
	T removeBack() {
		if(head == null) {
			return null;
		}
		
		T data;
		if(length == 1) {
			data = head.data;
			head = null;
		} else {
			Node<T> tail = head.prevNode;
			Node<T> newTail = tail.prevNode;
			data = tail.data;
			newTail.nextNode = head;
			head.prevNode = newTail;
		}
		
		length--;
		return data;
	}
}
