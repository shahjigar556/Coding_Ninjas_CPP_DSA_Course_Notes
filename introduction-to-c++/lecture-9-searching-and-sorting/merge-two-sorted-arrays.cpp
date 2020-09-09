#include<iostream>
using namespace std;

// Print the array
void printArray(int arr[], int n) {
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

// Merge the two arrays
void merge(int arr1[], int size1, int arr2[], int size2, int ans[]) {
    int i = 0, j = 0, k = 0;
    while(i < size1 && j < size2) {
        if(arr1[i] < arr2[j]) {
            ans[k++] = arr1[i++];
        } else {
            ans[k++] = arr2[j++];
        }
    }
    if(i < size1) {
        while(i < size1) {
            ans[k++] = arr1[i++];
        }
    }
    if(j < size2) {
        while(j < size2) {
            ans[k++] = arr2[j++];
        }
    }   
    
}

int main() {
	int arr1[100], arr2[100], mergedArray[100];
	int size1;
	cout << "Enter the size of the first array: ";
	cin >> size1;
	int val;
	cout << "Enter the SORTED values of the first array: ";
	for(int i = 0; i < size1; i++) {
		cin >> arr1[i];
	}
	int size2;
	cout << "Enter the size of the second array: ";
	cin >> size2;
	cout << "Enter the SORTED values of the second array: ";
	for(int i = 0; i < size2; i++) {
		cin >> arr2[i];
	}
	merge(arr1, size1, arr2, size2, mergedArray);
	cout << "The first array: ";
	printArray(arr1, size1);
	cout << "The second array: ";
	printArray(arr2, size2);
	cout << "The merged array: ";
	printArray(mergedArray, size1 + size2);
}
