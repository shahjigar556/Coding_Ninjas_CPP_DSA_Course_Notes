/*
Knapsack: 
A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is value vi. What is the maximum value V, that thief can take ?
Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

// Brute Force
int knapsack(int* weight, int* values, int n, int maxWeight) {
    // Base case
	if(n == 0 || maxWeight == 0) {
		return 0;
	}

	if(weight[0] > maxWeight) {
		return knapsack(weight + 1, values + 1, n - 1, maxWeight);
	}

	// Recursive calls
	int x = knapsack(weight + 1, values + 1, n - 1, maxWeight - weight[0]) + values[0];
	int y = knapsack(weight + 1, values + 1, n - 1, maxWeight);

	return max(x, y);
}

// Memoization
int knapsack_mem_helper(int *weights, int *values, int n, int maxWeight, int **output) {
    // Base case
	if(maxWeight <= 0 || n==0) {
        if(maxWeight < 0)
            return -values[n];
        return 0;
    }
    if(output[n][maxWeight] == -1)
        output[n][maxWeight] = max((values[n - 1] + knapsack_mem_helper(weights, values, n - 1, maxWeight - weights[n - 1], output)),
                knapsack_mem_helper(weights, values, n - 1, maxWeight, output));
    return output[n][maxWeight];
}
int knapsack_mem(int *weight, int *values, int n, int maxWeight) {
    int **output = new int*[n + 1];
    for(int i = 0; i <= n; i++) {
        output[i] = new int[maxWeight + 1];
        for(int j = 0; j <= maxWeight; j++) {
            output[i][j] = -1;
        }
    }
    return knapsack_mem_helper(weight, values, n, maxWeight, output);
}

int main(){
    int n; 
	cin >> n;
	int* weight = new int[n];
	int* values = new int[n];

	for(int i = 0; i < n; i++){
		cin >> weight[i];
	}

	for(int i = 0; i < n; i++){
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack(weight, values, n, maxWeight) << endl;
    cout << knapsack_mem(weight, values, n, maxWeight) << endl;
}