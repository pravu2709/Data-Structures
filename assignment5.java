import java.util.Stack;
import java.util.LinkedList;

public class Main {

    static class Graph {    //Class for defining Graph
        int vertex;
        int flag=0;
        LinkedList<Integer>[] adjacencyList;    //Graphs' Adjacency List
		
		

        Graph(int vertex) {
            this.vertex = vertex;
            adjacencyList = new LinkedList[vertex];
            for (int i = 0; i < vertex; i++) {
                adjacencyList[i] = new LinkedList<>();
            }
        }
		
		

        public void edge_add(int src, int dstn) {    //Adding an edge to the Graph
            adjacencyList[src].addFirst(dstn);
        }
		
		

        public void topological_sort() {    // Topological Sort
            boolean[] visited = new boolean[vertex]; 			
            Stack<Integer> final_st = new Stack<>();		
            for (int i = 0; i < vertex; i++) {
            	if (!visited[i] ) {						        //Calling the helper fn and checing if the node is already visited
                    sort_helper(i, visited, final_st);
                }   	
            }
            System.out.println("Topological Sort of the Graph: ");
            int size = final_st.size();
            int[] result=new int[size];
            for (int i = 0; i <size ; i++) 
                System.out.print(final_st.pop() + " ");

        }
		
		

        public void sort_helper(int start, boolean[] visited, Stack<Integer> final_st) {
            visited[start] = true;
            for (int i = 0; i < adjacencyList[start].size(); i++) {
                int vertex = adjacencyList[start].get(i);
                if(visited[vertex] && !(final_st.contains(vertex)))	//checking if there exits a cycle
                {
            		System.out.println("Detected Cycle in the Graph at the vertex: "+vertex);
            		flag=vertex;		
            		
                }
                if (!visited[vertex])					//Checking for each node recursively
                {
                   sort_helper(vertex, visited, final_st);
                }
            }
            if(flag==0)
            final_st.push(start);

        }
    }


    public static void main(String[] args) {
	
    	Graph g=new Graph(10);	//Graph with no cycle
		g.edge_add(3,4);
    	g.edge_add(0,9);
    	g.edge_add(3,2);
    	g.edge_add(8,0);
    	g.edge_add(1,7);
    	g.edge_add(8,1);
    	g.edge_add(5,4);
    	g.edge_add(1,2);
    	g.edge_add(3,6);
    	g.edge_add(8,2);
    	g.edge_add(6,8);
    	g.edge_add(5,6);
    	g.edge_add(3,7);
    	g.edge_add(0,1);
    	g.edge_add(4,6);
    	
    	
    	
    	g.topological_sort();
		
    	System.out.println();
    	System.out.println();
		
        Graph g1=new Graph(10);	// Graph with cycle
    	g1.edge_add(0,1);
    	g1.edge_add(9,2);
    	g1.edge_add(8,9);
    	g1.edge_add(1,8);
		g1.edge_add(1,2);
    	g1.edge_add(1,7);
    	g1.edge_add(8,2);
    	g1.edge_add(6,2);
    	g1.edge_add(3,2);
    	g1.edge_add(3,7);
		g1.edge_add(3,6);	
        g1.edge_add(3,4);    
    	g1.edge_add(4,6);
		g1.edge_add(6,3);
    	g1.edge_add(5,4);
    	
    	
    	g1.topological_sort();
    	
    }
    }