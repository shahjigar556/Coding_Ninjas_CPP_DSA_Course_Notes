/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> DFS(int** edges, int n, int sv, int ev, bool* visited) {
    vector<int> vec;
    visited[sv] = true;
    if(sv == ev) {
        vec.push_back(sv);
        return vec;
    }
    for(int i = 0; i < n; i++) {
        if(i == sv) {
            continue;
        } else {
    		if(edges[sv][i] == 1 && !visited[i]) {
                vec = DFS(edges, n, i, ev, visited);
                if(vec.size() != 0) {
                    vec.push_back(sv);
                    return vec;
                }
            }
        }
    }
    return vec;
}

vector<int> getPath(int** edges, int n) {
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    }
    int v1, v2;
    cin >> v1 >> v2;
    vector<int> vec = DFS(edges, n, v1, v2, visited);
    delete[] visited;
    return vec;
}

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
	int** edges = new int*[V];
    for(int i = 0; i < V; i++) {
        edges[i] = new int[V];
        for(int j = 0; j < V; j++) {
            edges[i][j] = 0;
        }
    }
    for(int i = 0; i < E; i++) {
        cin >> tempX >> tempY;
        edges[tempX][tempY] = 1;
        edges[tempY][tempX] = 1;
    }
    
    vector<int> ans = getPath(edges, V);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    
    for(int i = 0; i < V; i++) {
        delete[] edges[i];
    }
    delete[] edges;

  return 0;
}
