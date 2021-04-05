
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
}
