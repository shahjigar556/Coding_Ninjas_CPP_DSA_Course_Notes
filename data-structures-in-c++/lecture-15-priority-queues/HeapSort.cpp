#include <iostream>
using namespace std;

void inplaceHeapSort(int pq[], int n) {
    // Build the heap in input array
    for(int i = 1; i < n; i++) {
        // up-heapify
        int childIndex = i;
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

    // Remove elements
    // down-heapify
    int size = n;
    while(size > 1) {
        int temp = pq[0];
        pq[0] = pq[size - 1];
        pq[size - 1] = temp;

        size--;

        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while(leftChildIndex < size) {
            int minIndex = parentIndex;
            // check for left child
            if(pq[minIndex] > pq[leftChildIndex]) {
                minIndex = leftChildIndex;
            } 
            // check for right child and make sure that right child in within bound
            if(rightChildIndex < size && pq[rightChildIndex] < pq[minIndex]) {
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
    }
    
}

int main() {
    int input[] = {5, 1, 2, 0, 8};
    inplaceHeapSort(input, 5);
    for(int i = 0; i < 5; i++) {
        cout << input[i] << " ";
    }
    cout << endl;
}

/*
We wil get output in decreasing order
For getting in increasing order, use Max Heap
*/