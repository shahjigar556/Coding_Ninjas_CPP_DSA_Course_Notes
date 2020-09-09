#include <iostream>
#include <queue>
using namespace std;


int main() {
    // inbuilt priority queue is by default max priority queue (i.e, it is max heap; swap when parent < child)
    priority_queue<int> pq;


    // insert --> void push(element) <-- void insert(element)
    pq.push(16);
    pq.push(1);
    pq.push(167);
    pq.push(7);
    pq.push(45);
    pq.push(32);

    cout << "SIze: " << pq.size() << endl; // getSize()
    cout << "Top: " << pq.top() << endl; // top most element in the queue [root of the heap]

    while(!pq.empty()) { // !pq.isEmpty()
        cout << pq.top() << endl; // getMax() for max heap
        pq.pop(); // void pop() <-- T removeMax() [for Max Heap] <-- remove root
    }
}

// To use the inbuilt min priority_queue (i.e, it is min heap; swap when parent > child), write the code given below:
/*
priority_queue<int, vector<int>, greater<int>> pq; // min heap
*/