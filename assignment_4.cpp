#include<bits/stdc++.h> 
#define INF 0x3f3f3f3f 
using namespace std; 

typedef pair<int, int> iPair;  // defining an integer pair
 
 // function to print the path 
void path_print(int parnt[], int i)
{    
    if (parnt[i]==-1) // i = source (base case)
        return; 
    path_print(parnt, parnt[i]); 
    printf("%d ", i);
}
// function to add edges between vertex
void edge_add(vector <pair<int, int> > adjacent[], int i, int j, int wght)
{ 
    adjacent[i].push_back(make_pair(j, wght)); 
    adjacent[j].push_back(make_pair(i, wght));
    cout<<"("<<i<<","<<j<<","<<wght<<")";//, j,wght,")}");
}    
// function to find and print the shortest path from single source to all other vertices
void path_shortest(vector<pair<int,int> > adjacent[], int k, int source) 
{ 
    priority_queue< iPair, vector <iPair> , greater<iPair> > prior_q;  // creating a priority queue
  
    vector<int> dist(k, INF);  // Vector creation for distance and initialising all the distances as infinity
    int parnt[k],i;
    for(int i=0;i<k;i++)
    parnt[i]=-1;
  
    prior_q.push(make_pair(0, source)); // inserting source into the priority queue
    dist[source] = 0; 

    while (!prior_q.empty()) 
    {        
        int u = prior_q.top().second; 
        prior_q.pop();   
          
        for (auto x : adjacent[u])  // to get all the adjacent of u
        { 
            int v = x.first;   // to get the vertex label
            int weight = x.second; // getting the weight of the edge
  
            if (dist[v] > dist[u] + weight)  // checking if there is a shorter path from u to v
            { 
                dist[v] = dist[u] + weight;  // updating the new weight
                parnt[v]=u;
                prior_q.push(make_pair(dist[v], v)); 
            } 
        } 
    }  
    printf("Source_vertex\tDestination_vertex\tShortest_Distance\tPath");
    for ( i = 0; i < k; ++i) 
    {
        printf("\n%d\t\t%d\t\t\t%d\t\t\t",source, i, dist[i]); 
        path_print(parnt, i);    
    } 
}  
// main program to run the get the graph details
int main()  
{ 
    int Vertex = 10; 
    vector<iPair > adjacent[Vertex];  
    printf("list of vertices and their edges");
    printf("(source,edge,weight) \n{");
    edge_add(adjacent, 0, 1, 8); 
    edge_add(adjacent, 0, 6, 10); 
    edge_add(adjacent, 1, 2, 12); 
    edge_add(adjacent, 1, 6, 1); 
    edge_add(adjacent, 2, 3, 6); 
    edge_add(adjacent, 2, 7, 5); 
    edge_add(adjacent, 2, 5, 9); 
    edge_add(adjacent, 3, 4, 4); 
    edge_add(adjacent, 3, 6, 7); 
    edge_add(adjacent, 4, 5, 2); 
    edge_add(adjacent, 5, 6, 5); 
    edge_add(adjacent, 6, 7, 9);
    edge_add(adjacent, 7, 8, 2); 
    edge_add(adjacent, 7, 9, 6);
	edge_add(adjacent, 8, 9, 4);
	edge_add(adjacent, 9, 6, 2); 
	printf("}\n\n");
	printf("Output after running dijkstra's algorithm\n\n");
    path_shortest(adjacent, Vertex, 0);   
    return 0; 
} 