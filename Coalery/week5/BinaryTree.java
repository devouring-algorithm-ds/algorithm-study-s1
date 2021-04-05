
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
