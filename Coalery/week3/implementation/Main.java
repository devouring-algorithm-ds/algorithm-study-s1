// if you want to use 'assert', then run with the '-ea' argument.

public class Main {
	public static void main(String[] args) {
		final String format = "-------------------- [ %s ] --------------------";
		
		{
			System.out.println(String.format(format, "Stack"));
			
			Stack<Integer> stack = new Stack<>();
			
			assert(stack.pop() == null);
			assert(stack.peek() == null);
			assert(stack.isEmpty());
			
			for(int i=0; i<5; i++)
				stack.push(i);
			// 0 1 2 3 4
			
			assert stack.pop() == 4;
			assert stack.peek() == 3;
			assert !stack.isEmpty();
			
			while(!stack.isEmpty())
				System.out.println(stack.pop());
			// 3 2 1 0
		}
		
		{
			System.out.println(String.format(format, "Queue"));
			
			Queue<Integer> queue = new Queue<>();
			
			assert(queue.dequeue() == null);
			assert(queue.getFront() == null);
			assert(queue.getBack() == null);
			assert(queue.isEmpty());
			
			for(int i=0; i<5; i++)
				queue.enqueue(i);
			// 0 1 2 3 4
			
			assert(queue.dequeue() == 0); // Dequeue!
			assert(queue.getFront() == 1);
			assert(queue.getBack() == 4);
			assert(!queue.isEmpty());
			
			while(!queue.isEmpty())
				System.out.println(queue.dequeue());
			// 1 2 3 4
		}
	}
}
