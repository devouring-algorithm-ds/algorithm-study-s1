
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
	
	public void insertAt(int pos, T data) {
		if(pos < 0 || pos >= length) return;
		
		if(pos == 0) {
			insertFront(data);
			return;
		} else if(pos == length - 1) {
			insertLast(data);
			return;
		}
		
		Node<T> temp = head;
		for(int i=0; i<pos - 1; i++)
			temp = temp.next;
		
		Node<T> newNode = new Node<>(data);
		Node<T> nextNode = temp.next;
		
		newNode.next = nextNode;
		temp.next = newNode;
		
		length++;
	}
	
	public T removeAt(int pos) {
		if(pos < 0 || pos >= length) return null;
		
		if(pos == 0)
			return removeFront();
		else if(pos == length - 1)
			return removeLast();
		
		Node<T> temp = head;
		for(int i=0; i<pos - 1; i++)
			temp = temp.next;
		
		Node<T> targetNode = temp.next;
		T data = targetNode.data;
		
		Node<T> nextNode = targetNode.next;
		temp.next = nextNode;
		
		targetNode = null;
		
		length--;
		return data;
	}
}
