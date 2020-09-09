/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
*/

#include <bits/stdc++.h>
using namespace std;


bool print_BFS(int **edges, int n, int sv, int ev, bool *visited, unordered_map<int, int> &hm) {
    // It is similar to level order traversal in tree
    queue<int> pendingVertices;
    hm[sv] = sv;
    pendingVertices.push(sv);
    visited[sv] = true;
    while(!pendingVertices.empty()) {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        for(int i = 0; i < n; i++) {
            if(i == currentVertex) {
                continue;
            }
            if(edges[currentVertex][i] == 1 && !visited[i]) {
                hm[i] = currentVertex;
                if(i == ev) {
                    return true;
                }
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    return false;
}
bool BFS(int** edges, int n, int sv, int ev, unordered_map<int, int> &hm) {
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    }
    bool getPath = print_BFS(edges, n, sv, ev, visited, hm);
    delete[] visited;
    return getPath;
}

int main()
{
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
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
	
    int v1, v2;
    cin >> v1 >> v2;
    unordered_map<int, int> hm;
    // vector<int> v;
    int i = v2;
    if(BFS(edges, n, v1, v2, hm)) {
        while(i != v1) {
            cout << i << " ";
            i = hm[i];
        }
        cout << v1;
    }
    
    // Delete all the memory
    for(int i = 0; i < n; i++) {
        delete[] edges[i];
    }
    delete[] edges;

  return 0;
}
