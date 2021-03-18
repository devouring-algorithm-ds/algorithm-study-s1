
public class ExtendedDoublyLinkedList<T> extends DoublyLinkedList<T> {
	public void insertAt(int pos, T data) {
		if(pos < 0 || pos >= length) return;
		
		if(pos == 0) {
			insertFront(data);
			return;
		} else if(pos == length - 1) {
			insertBack(data);
			return;
		}
		
		Node<T> temp = head;
		for(int i=0; i<pos - 1; i++)
			temp = temp.nextNode;
		
		Node<T> newNode = new Node<>(data);
		Node<T> nextNode = temp.nextNode;
		
		newNode.prevNode = temp;
		newNode.nextNode = nextNode;
		
		nextNode.prevNode = newNode;
		temp.nextNode = newNode;
		
		length++;
	}
	
	public T removeAt(int pos) {
		if(pos < 0 || pos >= length) return null;
		
		if(pos == 0)
			return removeFront();
		else if(pos == length - 1)
			return removeBack();
		
		Node<T> temp = head;
		for(int i=0; i<pos - 1; i++)
			temp = temp.nextNode;
		
		Node<T> targetNode = temp.nextNode;
		T data = targetNode.data;
		
		Node<T> nextNode = targetNode.nextNode;
		temp.nextNode = nextNode;
		nextNode.prevNode = temp;
		
		targetNode = null;
		
		length--;
		return data;
	}
}
