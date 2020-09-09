/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

bool print_BFS(int **edges, int n, int sv, int ev, bool *visited) {
    // It is similar to level order traversal in tree
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;
    while(!pendingVertices.empty()) {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        // cout << currentVertex << " ";
        for(int i = 0; i < n; i++) {
            if(i == currentVertex) {
                continue;
            }
            if(edges[currentVertex][i] == 1 && !visited[i]) {
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
bool BFS(int** edges, int n, int v1, int v2) {
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    }
    return print_BFS(edges, n, v1, v2, visited);
    delete[] visited;
}

bool check(int **edges, int n) {
    int v1, v2;
    cin >> v1 >> v2;
    if(edges[v1][v2] == 1) {
        return true;
    } else {
        return BFS(edges, n, v1, v2);
    }
}

int main(){
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

    bool hasPath = check(edges, n);
    if(hasPath) cout << "true" << endl;
    else cout << "false" << endl;

    // Delete all the memory
    for(int i = 0; i < n; i++) {
        delete[] edges[i];
    }
    delete[] edges;   
}