#include <vector>
using namespace std;


/******************************************************************************************************************************
 * Minimum Priority Queue [Parent is smaller than children and root is the minimum element] --> min heap
 */

class PriorityQueue {
    vector<int> pq; // define priority queue using a array

    public:
    PriorityQueue() {
        // This constructor only initializes pq and nothing else
    }
    bool isEmpty() {
        return pq.size() == 0;
    }

    // Return size of priorityQueue - no of elements of present
    int getSize() {
        return pq.size();
    }

    int getMin() {
        if(isEmpty()) {
            return 0; // Priority Queue is empty
        }
        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element); // maintain the CBT property

        int childIndex = pq.size() - 1;

        // Maintain the heap property
        // up-heapify
        while(childIndex > 0) {
			int parentIndex = (childIndex - 1) / 2;

			if(pq[childIndex] < pq[parentIndex]) {
				int temp = pq[childIndex];
				pq[childIndex] = pq[parentIndex];
				pq[parentIndex] = temp;
			}
			else {
				break;
			}
			childIndex = parentIndex;
		}
    }

    int removeMin() {
        if(isEmpty()) {
            return 0; // Priority Queue is empty
        }
        int ans = pq[0];
		pq[0] = pq[pq.size() - 1];
		pq.pop_back();

        // down-heapify
        int parentIndex = 0;
		int leftChildIndex = 2 * parentIndex + 1;
		int rightChildIndex = 2 * parentIndex + 2;
        // loop as long as left child is within bounds. 
        // If left child is not within bounds, then right child will automatically be out of bounds 
        while(leftChildIndex < pq.size()) {
			int minIndex = parentIndex;
            // check for left child
            if(pq[minIndex] > pq[leftChildIndex]) {
				minIndex = leftChildIndex;
			} 
            // check for right child and make sure that right child in within bound
            if(rightChildIndex < pq.size() && pq[rightChildIndex] < pq[minIndex]) {
				minIndex = rightChildIndex;
			}
            // check if rest of the heap is heapified
            if(minIndex == parentIndex) {
				break;
			}
            // swap
            int temp = pq[minIndex];
			pq[minIndex] = pq[parentIndex];
			pq[parentIndex] = temp;
            // updated indexes
            parentIndex = minIndex;
			leftChildIndex = 2 * parentIndex + 1;
			rightChildIndex = 2 * parentIndex + 2;
        }

        return ans;
    }
};

/*
    Best way to implement a priority queue is by using heap.
    There are two types of heap(one type of BT),
    1. minHeap --> root is less than it's children
    2. maxHeap --> root is greater than it's children
    A priority queue must satisfy the CBT(Complete Binary Tree) property and Heap property
    Priority Queue (Heap) might be defined as a array but always visualize it as a "Heap Sorted CBT"
*/

/*
PriorityQueue -> 1 2 3 4 5 6 7 8
Positon of children in array of node at ith position in array --> ((2 * i) + 1) and ((2 * i) - 1)
Position parent in array for ith element in array --> (int)((i - 1) / 2)
*/

/*
 * It's called HEAP SORT
 * decreasing order --> min heap
 * increasing order --> max heap
 * 
 * Time Complexity of inserting all elements in Heap Sort: O(nlogn)
 * Time Complexity of removing all elements from Heap Sort: O(nlogn)
 * Overall Time Complexity: O(nlogn)
 * 
 * Space Complexity: O(n) <-- we are using a extra vector of n length other than the data that was provided
*/