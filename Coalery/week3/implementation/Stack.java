
public class Stack<T> {
	private Node<T> top;
	
	public void push(T data) {
		Node<T> temp = new Node<>(data);
		temp.next = top;
		top = temp;
	}
	
	public T pop() {
		if(isEmpty()) return null;
		
		T data = top.data;
		top = top.next;
		
		return data;
	}
	
	public T peek() {
		if(isEmpty()) return null;
		return top.data;
	}
	
	public boolean isEmpty() {
		return top == null;
	}
}
