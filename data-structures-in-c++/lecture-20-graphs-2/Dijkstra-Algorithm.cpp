#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int findMinVertex(int* distance, bool* visited, int n){

	int minVertex = -1;
	for(int i = 0; i < n; i++){
		if(!visited[i] && (minVertex == -1 ||  distance[i] < distance[minVertex])){
			minVertex = i;
		}
	}
	return minVertex;
}

void dijkstra(int** edges, int n){
	int* distance = new int[n];
	bool* visited = new bool[n];

	for(int i = 0; i < n; i++){
		distance[i] = INT_MAX;
		visited[i] = false;
	}

	distance[0] = 0;

	for(int i = 0; i < n - 1; i++){ // As we don't need to check the neighbors of our destination so, we can run it n-1 times
		int minVertex = findMinVertex(distance, visited, n);
		visited[minVertex] = true;
		for(int j = 0; j < n; j++){	
			if(edges[minVertex][j] != 0 && !visited[j]){
				int dist = distance[minVertex] + edges[minVertex][j];
				if(dist < distance[j]){
					distance[j] = dist;
				}
			}
		}
	}

	for(int i = 0; i < n; i++){
		cout << i << " " << distance[i] << endl;
	}
	delete [] visited;
	delete [] distance;
	
}

int main() {
	int n;
	int e;
	cin >> n >> e;
	int** edges = new int*[n];
	for (int i = 0; i < n; i++) {
		edges[i] = new int[n];
		for (int j = 0; j < n; j++) {
			edges[i][j] = 0;
		}
	}

	for (int i = 0; i < e; i++) {
		int f, s, weight;
		cin >> f >> s >> weight;
		edges[f][s] = weight;
		edges[s][f] = weight;
	}
	cout << endl;
	dijkstra(edges, n);

	for (int i = 0; i < n; i++) {
		delete [] edges[i];
	}
	delete [] edges;
}


/*
Time Complexity: O(n^2)

We can improve it. If we use adjacency list, then we will only go to the neighbors and not unnecessarily traval through all the vertices that we are dong beccause we are using adjacency matrices.

Second optimizes is to use priority queue in the case of findMinVertex with the distance being the priority. We will need to customize the priority queue so that the priority queue automatically heapifies as we change the distance of the minVertex and get updated.

So, improved time complexity: O((n + E)logn)
*/