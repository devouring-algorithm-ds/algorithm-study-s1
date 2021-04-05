
public class Queue<T> {
	private Node<T> front;
	private Node<T> back;
	
	public void enqueue(T data) {
		Node<T> temp = new Node<>(data);
		
		if(isEmpty()) {
			front = temp;
			back = temp;
		} else {
			back.next = temp;
			back = back.next;
		}
	}
	
	public T dequeue() {
		if(isEmpty()) return null;
		
		T data = front.data;
		front = front.next;
		
		return data;
	}
	
	public T getFront() {
		if(isEmpty()) return null;
		return front.data;
	}
	
	public T getBack() {
		if(isEmpty()) return null;
		return back.data;
	}
	
	public boolean isEmpty() {
		return front == null;
	}
}