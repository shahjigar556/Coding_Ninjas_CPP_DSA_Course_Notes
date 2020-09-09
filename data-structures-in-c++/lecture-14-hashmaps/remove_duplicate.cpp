#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> removeDuplicates(int *a, int size) {
    vector<int> output;
    unordered_map<int, bool> seen;
    // Time complexity with Map: O(n) and without Map: O(logn)
    for(int i = 0; i < size; i++) { // Time Complexity O(n)
        if(seen.count(a[i]) > 0) { // If, map was not used then time complexity would be O(logn)
            continue; // key has a duplicate
        }
        seen[a[i]] = true; // There is no duplicate of this key
        output.push_back(a[i]);
    }
    return output;
}

int main() {

    int a[] = {1, 2, 3, 3, 2, 1, 4, 3, 6, 5, 5};
    vector<int> output = removeDuplicates(a, 11);
    for(int x : output) {
        cout << x << " "; // 1 2 3 4 6 5
    }
    cout << endl;

}