import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int min = 1000001, max = -1000001;
		int N = sc.nextInt();
		
		for(int i=0; i<N; i++) {
			int K = sc.nextInt();
			if(K < min) min = K;
			if(K > max) max = K;
		}
		
		sc.close();
		
		System.out.println(min + " " + max);
	}
}