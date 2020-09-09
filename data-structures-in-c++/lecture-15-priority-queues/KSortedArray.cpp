#include <iostream>
#include <queue>
using namespace std;

// Overall Time Complexity = O((n + k)logK)
// For a very small value of k and for a large value of n, time complexity will be O(n)
void kSortedArray(int input[], int n, int k) { 
    priority_queue<int> pq; // max heap
    for(int i = 0; i < k; i++) { // Time Complexity of insert k elements in the heap is O(klogk)
        pq.push(input[i]);
    }

    int j = 0;
    for(int i = k; i < n; i++) { // Time Complexity of pop() (n - k) elements in the heap is O((n - k)logk)
        input[j] = pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }
    while(!pq.empty()) { // Time Complexity of pop() k elements in the heap is O(klogk)
        input[j++] = pq.top();
        pq.pop();
    }

}

int main() {
    int input[] = {10, 12, 6, 7, 9, 15};
    int n = sizeof(input) / sizeof(input[0]);
    kSortedArray(input, n, 3);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    cout << endl;
}