#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

class Edge {
    public:
        int source;
        int dest;
        int weight;
};

bool compare(Edge e1, Edge e2) {
    return e1.weight < e2.weight; // If e1.weight < e2.weight then it's ok. Otherwise rearrange
}

int findParent(int v, int *parent) {
    if(parent[v] == v) {
        return v;
    }
    return findParent(parent[v], parent);
}

void kruskals(Edge *input, int n, int E) {
    // Sort the input array - ascending order based on weights
    sort(input, input + E, compare);

    Edge *output = new Edge[n - 1]; // Array of all the Edges in our MST

    int *parent = new int[n]; // Array to keep track of the parents of all the vertices
    for(int i = 0; i < n; i++) {
        parent[i] = i; // Initially all vertices are parents of itself as all of them are disjoint set itself
    }

    int count = 0; // how many edges are added to our MST.
    int i = 0; // denotes the current edge
    while(count != n - 1) {
        Edge currentEdge = input[i];

        // Check if we can add the current edge in MST wuthout creating a cycle
        int sourceParent = findParent(currentEdge.source, parent); // This function finds the topmost parent element of the disjoint set that it is part of
        int destParent = findParent(currentEdge.dest, parent);

        if(sourceParent != destParent) {
            // Add the edge to the MST
            output[count] = currentEdge;
            count++;
            // Update their parents
            parent[sourceParent] = destParent;
        }
        i++;
    }

    // Print MST
    for(int i = 0; i < n - 1; i++) { // MST has only n - 1 edges
        if(output[i].source < output[i].dest)
            cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
        else
            cout << output[i].dest << " " << output[i].source << " " << output[i].weight << endl;
    }
}

int main(){
    int n, E;
    cin >> n >> E;
    Edge *input = new Edge[E]; // Array of all the Edges in the graph

    for(int i = 0; i < E; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        input[i]; // One object of class Edge
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    kruskals(input, n, E);
}

/*
Time Complexity:
1. Take input -> size = O(E)
2. Sort input array -> O(ElogE)
3. Pick n-1 edges and put in MST:
i. Perform Cycle detection: O(E*v) // O(v) time for E edges in worst case

Overall: O(ElogE + EV)
in worst case, E ~ V^2
So, in worst case, time complexity: O((V^2)log(V^2) + (V^3))

We can improve the time complexity by improving the cycle detection algorithm.
Right now we are using union-detection algorithm to detect the cycle.
There is a better version of this algorithm is: union by Rank & Path compression
In this case, cycle detection time complexity will be O(logV) and the overall time complexity will be,
            O(ElogE + ElogV)
*/

/*
Kruskals is a greedy algorithm.
Greedy algorithms means that if I have multiple options then I will pick the current one that seem best to me. 
*/