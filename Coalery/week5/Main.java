public class Main {
	public static void main(String[] args) {
		BinaryTree<Integer> btree = new BinaryTree<Integer>();
		
		for(int i=1; i<=15; i++)
			btree.insertNode(i);
		
		System.out.println("inorder");
		btree.inorder();
		System.out.println();
		
		System.out.println();
		System.out.println("preorder");
		btree.preorder();
		System.out.println();
		
		System.out.println();
		System.out.println("postorder");
		btree.postorder();
		System.out.println();
	}
}
