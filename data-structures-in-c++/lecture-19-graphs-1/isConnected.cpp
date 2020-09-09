/*
Given an undirected graph G(V,E), check if the graph G is connected graph or not.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
*/

#include <bits/stdc++.h>
using namespace std;

void print_DFS(int **edges, int n, int sv, bool *visited) {
    // cout << sv << " ";
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
bool DFS(int** edges, int n) {
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    }
    print_DFS(edges, n, 0, visited);
    bool isConnected = true;
    for(int i = 0; i < n; i++) {
        if(!visited[i])
            isConnected = false;
    }
    delete[] visited;
    return isConnected;
}

int main() {
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
    
    if(DFS(edges, n)) cout << "true" << endl;
    else cout << "false" << endl;

    // Delete all the memory
    for(int i = 0; i < n; i++) {
        delete[] edges[i];
    }
    delete[] edges;

  return 0;
}
