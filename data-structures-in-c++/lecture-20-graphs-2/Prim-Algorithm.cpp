#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int findMinVertex(int *weights, bool *visited, int n) {
    int minVertex = -1;
    for(int i = 0; i < n; i++) {
        if(!visited[i] && (minVertex==-1 || weights[i] < weights[minVertex])) {
            minVertex = i;
        }
    }
    return minVertex;
}

void prims(int **edges, int n) {
    int *parent = new int[n];
    int *weights = new int[n];
    bool *visited = new bool[n];

    for(int i = 0; i < n; i++) {
        visited[i] = false;
        weights[n] = INT_MAX;
    }
    parent[0] = -1;
    weights[0] = 0;

    for(int i = 0; i < n; i++) {
        // Find Min Vertex
        int minVertex = findMinVertex(weights, visited, n);
        // minVertex is visited
        visited[minVertex] = true;
        // Explore un-visited neighbours
        for(int j = 0; j < n; j++) {
            if(edges[minVertex][j] != 0 && !visited[j]) {
                if(edges[minVertex][j] < weights[j]) {
                    weights[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }

    cout << endl;
    for(int i = 1; i < n; i++) {
        if(parent[i] < i) {
            cout << parent[i] << " " << i << " " << weights[i] << endl;
        } else {
            cout << i << " " << parent[i] << " " << weights[i] << endl;
        }
    }

    delete[] parent;
    delete[] weights;
    delete[] visited;
}

int main(){
    int n;
    int e;
    cin >> n >> e;
    int **edges = new int*[n]; 
    for(int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for(int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }

    for(int i = 0; i < e; i++) {
        int f, s, weight;
        cin >> f >> s >> weight;
        edges[f][s] = weight;
        edges[f][s] = weight;
    }
    prims(edges, n);

    for(int i = 0; i < n; i++) {
        delete[] edges[i];
    }
    delete[] edges;
}

/*
Time Complexity of findMinVertex: O(n^2) [n times findMinVertex is called which in turn has O(n) time complexity]
Time complexity for exploring un-visited neighboes: O(n^2)
n is number of vertices

We are doing redundant work at exploring un-visited neighbors. To find neighbors, because of using adjacency matrix, we are required to traverse all the columns in a row matrix to find if there is an edge or not. We can save time here by using adjacency list here instead of adjacency matrix.

We can also reduce time for finding minimum vertex by using Priority Queue with the priority on weight. By using priority queue, we can find the minimum vertex faster (O(logn)). But we will need to customize the priority queue as the weights of the vertices might change dusing exploring the un-visited vertices. So, we will need to make changes to our priority queues at that time too.

So, after using priority queue and adjacency list we will get the time complexity O((E + n)logn) from O(n^2)
*/

/*
Prim's is a Greedy algorithm
*/