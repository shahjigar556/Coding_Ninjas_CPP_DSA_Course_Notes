#include<iostream>
using namespace std;

// Print the array
void printArray(int arr[], int n) {
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

// SORTING METHODS: Iterative method 

// SELECTION SORT
void selectionSort(int arr[], int n) {
	for(int i = 0; i < n - 1; i++) { // for n-1 rounds
		int minIndex = i;
		for(int j = i + 1; j < n; j++) {
			if(arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}

// BUBBLE SORT
void bubbleSort(int arr[], int n){
	
    for(int i = 0; i < n - 1; i++) {
        for(int j = 1; j < n - i; j++) {
            if(arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            } 
        }
    }

}

// INSERTION SORT
void insertionSort(int arr[], int n){
	for(int i = 1; i < n; i++) {
        int current = arr[i];
        int j;
        for(j = i - 1; j >= 0; j--) {
            if(current < arr[j]) {
                arr[j + 1] = arr[j]; 
            } else {
                break;
            }
        }
        arr[j + 1] = current;
    }
}

// BINARY SEARCH: Iterative method
int binarySearch(int arr[], int n, int val) {
	int start = 0, end = n -1;
	while(start <= end) {
		int mid = (start + end) / 2;
		if(val == arr[mid]) {
			return mid;
		} else if(val < arr[mid]) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}
	return -1;
}

int main() {
	int input[100];
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	
	// Take array input
	int val;
	cout << "Enter the values of the array: ";
	for(int i = 0; i < n; i++) {
		cin >> input[i];
	}
	
	// Display the array
	cout << "Your entered array is: ";
	printArray(input, n);
	
	// sort the array
	bool isSorted = true;
	while(isSorted) {
		int chooseSort;
		cout << "Which algorithm would you like to sort your array with?" << endl
			<< "1. Selection Sort" << endl
			<< "2. Bubble Sort" << endl
			<< "3. Insertion Sort" << endl 
			<< "=> ";
		cin >> chooseSort;
		switch(chooseSort) {
			case 1:
				selectionSort(input, n);
				isSorted = false;
				break;
			case 2:
				bubbleSort(input, n);
				isSorted = false;
				break;
			case 3:
				insertionSort(input, n);
				isSorted = false;
				break;
			default:
				cout << "The array needs to be sorted!!!";
		}
	}
			
	// Display sorted array
	cout << "The sorted array is: ";
	printArray(input, n);
		
	// search for the element
	int x;
	cout << "Enter the value that has to be searched: ";
	cin >> x;
	int index = binarySearch(input, n, x);
	if(index != -1) {
		cout << "The value is in the index " << index << " of the array";
	} else {
		cout << "The value is not present in the array";
	}
}
