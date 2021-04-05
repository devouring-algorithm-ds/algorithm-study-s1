
public class TreeNode<T> {
	T data;
	TreeNode<T> left;
	TreeNode<T> right;
	
	public TreeNode(T data) {
		this.data = data;
	}
	
	@Override
	public String toString() {
		String dataStr = "null";
		String leftStr = "null";
		String rightStr = "null";
		if(data != null) dataStr = data.toString();
		if(left != null) leftStr = left.toString();
		if(right != null) rightStr = right.toString();
		return String.format("TreeNode{data=%s,left=%s,right=%s}", dataStr, leftStr, rightStr);
	}
}
