
public class Main {
	public static void main(String[] args) {
		final String format = "-------------------- [ %s ] --------------------";
		
		{ // DoublyLinkedList
			System.out.println(String.format(format, "DoublyLinkedList"));
			
			DoublyLinkedList<Integer> dll = new DoublyLinkedList<>();
			
			System.out.println("Add 5 Items, Remove All from the front.");
			
			dll.insertFront(1);
			dll.insertFront(2);
			dll.insertFront(3);
			dll.insertBack(4);
			dll.insertBack(10);
			
			while(!dll.isEmpty()) {
				int data = dll.removeFront();
				System.out.println(data);
			}
			
			System.out.println();
			
			System.out.println("Add 5 Items, Remove All from the back.");
			
			dll.insertFront(1);
			dll.insertFront(2);
			dll.insertFront(3);
			dll.insertBack(4);
			dll.insertBack(10);
			
			while(!dll.isEmpty()) {
				int data = dll.removeBack();
				System.out.println(data);
			}
			
			System.out.println();
		} 
		
		{ // DoublyLinkedList with O(1) removeBack, insertBack
			System.out.println(String.format(format, "DoublyLinkedList with O(1) removeBack, insertBack"));
			
			DoublyLinkedList<Integer> dll = new DoublyLinkedList<>();
			
			System.out.println("Add 5 Items, Remove All from the front.");
			
			dll.insertFront(1);
			dll.insertFront(2);
			dll.insertFront(3);
			dll.insertBack(4);
			dll.insertBack(10);
			
			while(!dll.isEmpty()) {
				int data = dll.removeFront();
				System.out.println(data);
			}
			
			System.out.println();
			
			System.out.println("Add 5 Items, Remove All from the back.");
			
			dll.insertFront(1);
			dll.insertFront(2);
			dll.insertFront(3);
			dll.insertBack(4);
			dll.insertBack(10);
			
			while(!dll.isEmpty()) {
				int data = dll.removeBack();
				System.out.println(data);
			}
			
			System.out.println();
		}
		
		{ // DoublyLinkedList with insertAt, removeAt
			System.out.println(String.format(format, "DoublyLinkedList with O(1) removeBack, insertBack"));
			
			ExtendedDoublyLinkedList<Integer> edll = new ExtendedDoublyLinkedList<>();
			
			System.out.println("Add 5 Items, Insert 1 item, Remove 1 item, Remove All from the front.");
			
			edll.insertBack(1);
			edll.insertBack(2);
			edll.insertBack(3);
			edll.insertBack(4);
			edll.insertBack(5);
			
			edll.insertAt(2, 7);
			
			edll.removeAt(4);
			
			while(!edll.isEmpty()) {
				int data = edll.removeFront();
				System.out.println(data);
			}
			
			System.out.println();
		}
	}
}
