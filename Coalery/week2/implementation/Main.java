
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
		
		System.out.println();
		
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
	}
}
