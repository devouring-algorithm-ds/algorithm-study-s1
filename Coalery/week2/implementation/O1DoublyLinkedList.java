
public class O1DoublyLinkedList<T> {
	private Node<T> head;
	private Node<T> tail;
	private int length;
	
	boolean isEmpty() { return length <= 0; }
	
	void insertFront(T data) {
		Node<T> newNode = new Node<>(data);
		
		if(head == null) {
			head = newNode;
			tail = newNode;
		} else {
			newNode.nextNode = head;
			head.prevNode = newNode;
			head = newNode;
		}
		length++;
	}
	
	void insertBack(T data) {
		Node<T> newNode = new Node<>(data);
		
		if(head == null) {
			head = newNode;
			tail = newNode;
		} else {
			newNode.prevNode = tail;
			tail.nextNode = newNode;
			tail = newNode;
		}
		length++;
	}
	
	T removeFront() {
		if(length == 0) {
			return null;
		}
		
		T data = head.data;
		if(length == 1) {
			head = null;
			tail = null;
		} else {
			Node<T> temp = head.nextNode;
			temp.prevNode = null;
			head = temp;
		}
		
		length--;
		return data;
	}
	
	T removeBack() {
		if(length == 0) {
			return null;
		}
		
		T data;
		if(length == 1) {
			data = head.data;
			head = null;
			tail = null;
		} else {
			data = tail.data;
			Node<T> temp = tail.prevNode;
			temp.nextNode = null;
			tail = temp;
		}
		
		length--;
		return data;
	}
}
