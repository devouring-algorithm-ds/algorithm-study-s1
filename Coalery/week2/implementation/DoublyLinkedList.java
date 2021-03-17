
public class DoublyLinkedList<T> {
	protected Node<T> head;
	protected int length;
	
	boolean isEmpty() { return length <= 0; }
	
	void insertFront(T data) {
		Node<T> newNode = new Node<>(data);
		
		if(head == null) {
			head = newNode;
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
		} else {
			Node<T> temp = head;
			while(temp.nextNode != null) {
				temp = temp.nextNode;
			}
			temp.nextNode = newNode;
			newNode.prevNode = temp;
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
			Node<T> temp = head.nextNode;
			temp.prevNode = null;
			head = temp;
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
			Node<T> temp = head;
			while(temp.nextNode.nextNode != null) {
				temp = temp.nextNode;
			}
			data = temp.nextNode.data;
			temp.nextNode = null;
		}
		
		length--;
		return data;
	}
}
