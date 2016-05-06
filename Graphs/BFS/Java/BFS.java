
import java.util.*;

class BFS {
	static int matrix[][];
	static int n, count;
	static int[][] index;
	static List<String> edges = new ArrayList<String>();
	static Queue<Integer> queues[];

	public static void main(String args[]) {
		Scanner x = new Scanner(System.in);

		System.out.print("Size of matrix: ");
		n = x.nextInt();
		matrix = new int[n][n];
                queues = new LinkedList[n];
		for(int i=0;i<n;i++) queues[i] = new LinkedList<>();

		System.out.println("Enter the matrix: ");
		for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
              	matrix[i][j] = x.nextInt();
				if(matrix[i][j]!=0) {
					count++;
					edges.add(String.valueOf(i+1) + String.valueOf(j+1));
				}
            }
		}

		createIndexes();

		//Indexing from 1
		int start;
		System.out.println("Starting node: ");
		start = x.nextInt();

		System.out.println("\nEgdes: " + edges);

		System.out.println("BFS Traversal: ");
		breadthFirstTraverse(start);
	}

	private static void createIndexes() {
		
		for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
				if(matrix[i][j]==1) {
       				queues[i].add(j+1);
				}
            }
		}
	}

	private static void breadthFirstTraverse(int start) {
	    boolean[] visited = new boolean[n+1];
            Queue<Integer> queue = new LinkedList<Integer>();
            
            visited[start] = true;
            queue.add(start);
            
            while(!queue.isEmpty()) {
                int value = queue.poll();
                System.out.print(value + " ");
                
                Iterator<Integer> iterator = queues[value-1].iterator();
                while(iterator.hasNext()) {
                    int temp = iterator.next();
                    
                    if(!visited[temp]) {
                        visited[temp] = true;
                        queue.add(temp);
                    }
                }
                
            }
	}

	private static void displayMatrix() {
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				System.out.print(matrix[i][j] + " ");
			}
			System.out.println();
		}
	}
}