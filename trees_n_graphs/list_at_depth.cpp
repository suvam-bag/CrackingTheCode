/*List of Depths - Given a binary tree, design an algorithm which creates
a linked list of all the nodes at each depth (for depth, D, you will have D linked lists)*/

// 1. BFS
// 2. For i level BFS, append children to array of linked lists

#include <iostream>
#include <list>

using namespace std;



// This class represents a directed graph using 
// adjacency list representation 
class Graph {
private:
	int V; //No of vertices
	list<int> *adj; //Pointer to an array containing adjacency lists
	list<int> linkedListArray[100];; //Pointer to an array containing adjacency lists
public:
	Graph(int V); //constructor
	void addEdge(int v, int w); //func to add edge to graph
	bool BFS(int s); //prints BFS traversal from a given source s
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {

	adj[v].push_back(w); //Add w to v's list
}
bool Graph::BFS(int s) {


	//mark all the vertices as not visited
	//ptr to bool array
	bool *visited = new bool[V];
	for (int i=0; i<V; i++) {
		visited[i] = false;
	}

	//create a queue for BFS
	list<int> queue;

	// 'i' will be used to get all adjacent 
    // vertices of a vertex 
    list<int>::iterator i; 

    while (!queue.empty()) { //traverse entire tree/graph
    	//dequeue a vertex from queue and print it
    	s = queue.front();
    	cout << s << " ";
    	queue.pop_front(); 

    	// Get all adjacent vertices of the dequeued 
        // vertex s. If a adjacent has not been visited,  
        // then mark it visited and enqueue it 
        int count = 0;
        for (i = adj[s].begin(); i != adj[s].end(); i++) {
        	if (!visited[*i]) {
        		visited[*i] = true; 
                queue.push_back(*i);
                linkedListArray[count].push_back(adj[s]);
                count += 1;
        	}
        	else {
        		return true;
        	}
        	list<int>::iterator iter = linkedListArray[count].begin();
		    while (iter != linkedListArray[count].end())
		    {
		      cout << '\t' << *iter << '\n';
		      iter++;
		    }
        }
    }

    

    return false;
}

// Driver program to test methods of graph class 
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 0) \n"; 
    if (!g.BFS(0)) {
    	cout << "node is found\n";
    } 
  
    return 0; 
} 