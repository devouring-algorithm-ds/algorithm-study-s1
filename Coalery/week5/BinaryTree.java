
public class BinaryTree<T> {
	private TreeNode<T> root;
	
	public void insertNode(T data) {
		if(root == null) {
			root = new TreeNode<>(data);
			return;
		}
		
		Queue<TreeNode<T>> Q = new Queue<>();
		Q.enqueue(root);
		
		while(!Q.isEmpty()) {
			TreeNode<T> temp = Q.dequeue();
			
			if(temp.left != null)
				Q.enqueue(temp.left);
			else {
				temp.left = new TreeNode<>(data);
				return;
			}
			
			if(temp.right != null)
				Q.enqueue(temp.right);
			else {
				temp.right = new TreeNode<>(data);
				return;
			}
		}
	}
	
	public void inorder() { inorderHelper(root); }
	
	public void preorder() { preorderHelper(root); }
	
	public void postorder() { postorderHelper(root); }
	
	public T deleteNode() {
		if(root == null) return null;
		
		TreeNode<T> lastNode = null;
		T result = null;
		
		Queue<TreeNode<T>> Q = new Queue<>();
		Q.enqueue(root);
		
		while(!Q.isEmpty()) {
			lastNode = Q.dequeue();
			result = lastNode.data;
			
			if(lastNode.left != null) Q.enqueue(lastNode.left);
			if(lastNode.right != null) Q.enqueue(lastNode.right);
		}
		
		TreeNode<T> parent = searchParent(root, lastNode);
		
		if(lastNode.equals(parent.left))
			parent.left = null;
		else if(lastNode.equals(parent.right))
			parent.right = null;
		
		return result;
	}
	
	private TreeNode<T> searchParent(TreeNode<T> root, TreeNode<T> target) {
		if(root == null) return null;
		if(target == null) return null;
		
		if(root.left != null && target.equals(root.left)) return root;
		if(root.right != null && target.equals(root.right)) return root;
		
		TreeNode<T> result = null;
		
		result = searchParent(root.left, target);
		result = searchParent(root.right, target);
		
		return result;
	}
	
	private void inorderHelper(TreeNode<T> root) {
		if(root == null) return;
		inorderHelper(root.left);
		System.out.print(root.data + " ");
		inorderHelper(root.right);
	}
	
	private void preorderHelper(TreeNode<T> root) {
		if(root == null) return;
		System.out.print(root.data + " ");
		preorderHelper(root.left);
		preorderHelper(root.right);
	}
	
	private void postorderHelper(TreeNode<T> root) {
		if(root == null) return;
		postorderHelper(root.left);
		postorderHelper(root.right);
		System.out.print(root.data + " ");
	}
}
