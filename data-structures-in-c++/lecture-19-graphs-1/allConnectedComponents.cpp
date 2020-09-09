/*
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

vector<int> print_DFS(int **edges, int n, int sv, bool *visited, vector<int> &vec) {
    vec.push_back(sv);
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
            print_DFS(edges, n, i, visited, vec);
        }
    }
    return vec;
}
vector<vector<int>> DFS(int** edges, int n) {
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    }
    vector<vector<int>> v;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
        	vector<int> temp;
            v.push_back(print_DFS(edges, n, i, visited, temp));
            temp.clear();
        }
    }
    delete[] visited;
    return v;
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

    vector<vector<int>> ans = DFS(edges, n);
    for(size_t i = 0; i < ans.size(); i++) {
        sort(ans[i].begin(), ans[i].end());
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    // Delete all the memory
    for(int i = 0; i < n; i++) {
        delete[] edges[i];
    }
    delete[] edges;   
}
