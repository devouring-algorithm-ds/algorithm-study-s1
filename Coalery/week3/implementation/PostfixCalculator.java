
public class PostfixCalculator {
	
	private int getPriority(char c) {
		if(c == '*' || c == '/') return 2;
		else if(c == '+' || c == '-') return 1;
		return 0;
	}
	
	private boolean isOperator(char c) {
		return (c == '+' || c == '-' || c == '*' || c == '/');
	}
	
	private boolean isNumber(char c) {
		return '0' <= c && c <= '9'; 
	}
	
	private String transform(String inFix) {
		Stack<Character> stack = new Stack<>();
		String postFix = "";
		
		for(char ch : inFix.toCharArray()) {
			if(ch == '(') {
				stack.push('(');
			} else if(ch == ')') {
				while(!stack.isEmpty() && stack.peek() != '(')
					postFix += stack.pop();
				stack.pop(); // '(' ¹ö¸²
			} else if(isOperator(ch)) {
				int priority = getPriority(ch);
				while(!stack.isEmpty() && getPriority(stack.peek()) >= priority)
					postFix += stack.pop();
				stack.push(ch);
			} else if(isNumber(ch)) {
				postFix += ch;
			}
		}
		
		while(!stack.isEmpty())
			postFix += stack.pop();
		
		return postFix;
	}
	
	public int calculate(String inFix) {
		Stack<Integer> stack = new Stack<>();
		String postFix = transform(inFix);
		
		for(char ch : postFix.toCharArray()) {
			if(isNumber(ch))
				stack.push(Integer.parseInt(ch + ""));
			else if(isOperator(ch)) {
				int a = stack.pop();
				int b = stack.pop();
				
				switch(ch) {
				case '+':
					stack.push(b + a); break;
				case '-':
					stack.push(b - a); break;
				case '*':
					stack.push(b * a); break;
				case '/':
					stack.push(b / a); break;
				}
			}
		}
		
		return stack.pop();
	}
	
}
