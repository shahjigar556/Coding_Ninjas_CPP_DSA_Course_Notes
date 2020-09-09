#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

void print_DFS(int **edges, int n, int sv, bool *visited) {
    cout << sv << " ";
    visited[sv] = true; // mark as visited
    for(int i = 0; i < n; i++) {
        if(i == sv) {
            continue;
        }
        if(edges[sv][i] == 1) {
            // Check if i is already been visied or not
            if(visited[i]) {
                continue;
            }
            // if there is an edge between the starting vertex and i then call print again with i as starting vertex
            print_DFS(edges, n, i, visited);
        }
    }
}

void print_BFS(int **edges, int n, int sv, bool *visited) {
    // It is similar to level order traversal in tree
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;
    while(!pendingVertices.empty()) {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout << currentVertex << " ";
        for(int i = 0; i < n; i++) {
            if(i == currentVertex) {
                continue;
            }
            if(edges[currentVertex][i] == 1 && !visited[i]) {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}

void DFS(int** edges, int n) {
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    }
    for(int i = 0; i < n; i++) {
        if(!visited[i])
            print_DFS(edges, n, i, visited);
    }
    delete[] visited;
}

void BFS(int** edges, int n) {
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    }
    for(int i = 0; i < n; i++) {
        if(!visited[i])
            print_BFS(edges, n, i, visited);
    }
    delete[] visited;
}

int main(){
    // Creating Graph through Adjacency Matrix
    int n; // number of vertices [0...n-1]
    int e; // number of edges
    cin >> n >> e;

    // Creating the adjacency matrix
    int** edges = new int*[n];
    for(int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for(int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }

    // Filling the adjacency matrix with proper edges
    for(int i = 0; i < e; i++) {
        int f, s; // first and second vertices
        cin >> f >> s;
        // As it is a bidirectional/undirectional graph so it will have edges from first vertices to second vertices and vice-versa
        edges[f][s] = 1; // edge directed from f to s
        edges[s][f] = 1; // edge directed from s to f
    }

    /*
    // We need a visited array so that we do not traverse through the nodes that we already traversed through
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    }
    // This is DFS traversal
    cout << "DFS: "; 
    print_DFS(edges, n, 0, visited); // 0 is the starting vertex for printing the graph
    cout << endl;

    // Reset the visited array
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    }
    // BFS traversal
    cout << "BFS: ";
    print_BFS(edges, n, 0, visited);
    */

    // For disconnected graphs
    cout << "DFS: ";
    DFS(edges, n);
    cout << endl;
    cout << "BFS: ";
    BFS(edges, n);

    // Delete all the memory
    for(int i = 0; i < n; i++) {
        delete[] edges[i];
    }
    delete[] edges;
    // delete[] visited;
}

/*
NOTES:

* Graphs:  A graph is a set of vertices and the edges connecting them. Graphs are used in a lot of the real life cases. For example, 
i> in case of facebook let's say that each user is a node(vertex) and they are connected between them. The connection between them will be edges. So, if we wish to connect different people in a social media, we will be using graphs. 
ii> Roads connecting different cities is a example of graph.
iii> Tree is also a graph but it is a special king of graph. Tree is a acyclic(does not contain any cycles) connected(all nodes are connected to eah other) graph.

* Adjacent Vertices: Two vertices are called adjacents if they have a direct edge between them.

* Degree: The number of edges connected to a vertices is the degree of that vertex.

* Path: Collection of edges through which we can reach from one point to another

* Connected graph: For every two vertices, there is a path between them.

* Connected Components: Components consists of vertices and edges. And all the components make a graph. Each component is not connected to each other.

* Tree: Tree is a connected graph which does not have any cycle

* A graph with n vertices will have minimum 0 edges for a graph and n-1 edges(O(n) time complexity) for a connected graph(A graph with minimum number of edges is basically a Tree)

* A complete graph(every vertex has a edge with every other vertex) with n vertices will have minimum number of nC2 i.e, (n*(n-1)/2) edges(O(n^2) time complexity). 

* DFS [Depth First Search]: It means once we go into one direction, we will keep going into depth till the point we can't go anymore.

* The minimum number of edges in a connected graph is of order O(n) and the maximum number of edges in a connected graph is of order O(n^2), where n is the number of vertices. So, any algoeithm that works in terms of number of edges then it's time complexity for worst case will be O(n^2). So, any algorithm that works in terms of number of edges then it works quadritaccly ratehr than linearly.

* BFS [Breadth First Search]: It's similar to level order traversal in trees

* Directed Graphs: A graph with directed edges. that means, edges[i][j] = 1 does not necessarily imply, edges[j][i] = 1

* Weighted Graphs: Edges have values/weightage/imporatnce. [e.g: Length of the road connecting two roads]
    edges[i][j] = edge of the weight

*/