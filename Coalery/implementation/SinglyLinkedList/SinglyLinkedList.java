
public class SinglyLinkedList<T> {
	private Node<T> head;
	private int length;
	
	public SinglyLinkedList() {
		length = 0;
	}
	
	public boolean isEmpty() {
		return length <= 0;
	}
	
	public int getLength() {
		return length;
	}
	
	public void insertFront(T data) {
		Node<T> newNode = new Node<>(data);
		if(length == 0) {
			head = newNode;
		} else {
			newNode.next = head;
			head = newNode;
		}
		length++;
	}
	
	public void insertLast(T data) {
		Node<T> newNode = new Node<>(data);
		if(length == 0) {
			head = newNode;
		} else {
			Node<T> temp = head;
			while(temp.next != null)
				temp = temp.next;
			temp.next = newNode;
		}
		length++;
	}
	
	public T removeFront() {
		if(length == 0) return null;
		
		T data = head.data;
		if(length == 1) {
			head = null;
		} else {
			Node<T> temp = head.next;
			head = temp;
		}
		
		length--;
		return data;
	}
	
	public T removeLast() {
		if(length == 0) return null;
		
		T data;
		if(length == 1) {
			data = head.data;
			head = null;
		} else {
			Node<T> temp = head;
			while(temp.next.next != null)
				temp = temp.next;
			data = temp.next.data;
			temp.next = null;
		}
		
		length--;
		return data;
	}
}
