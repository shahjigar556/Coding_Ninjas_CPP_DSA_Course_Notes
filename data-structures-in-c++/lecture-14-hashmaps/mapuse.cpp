#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    unordered_map<string, int> ourmap; // key is of type "string" and value is of type "int"

    // insert
    // Method 1:
    pair<string, int> p("abc", 1);
    ourmap.insert(p); // under the hood, unordered_map stores pair
    // Method 2:
    ourmap["def"] = 2;
    ourmap["def"] = 3;


    // find or access
    // Method 1
    cout << ourmap["abc"] << endl; // 1
    // Method 2
    cout << ourmap.at("def") << endl; // 2

    // cout << ourmap.at("ghi") << endl; 
    // terminate called after throwing an instance of 'std::out_of_range' <- exception
    cout << ourmap["ghi"] << endl; // 0
    // if this key does not exist, then [] will insert default value(which is 0) to that key


    // check presense
    if(ourmap.count("ghi") > 0)  {
    // count tells us, how many times a particular key came. In map, a particular key can come only once
    // So, count either returns 0 (key never used) or 1 (key is already used)
        cout << "Exists" << endl; 
    } else {
        cout << "Does not exist" << endl;
    }


    // size
    cout << ourmap.size() << endl; // 3


    // erase
    ourmap.erase("ghi");
    cout << ((ourmap.count("ghi") > 0) ? "Exists" : "Does not Exist") << endl;
    cout << ourmap.size() << endl; // 2

}

/*
There are two types of maps:
1. Ordered Map - uses Self-balancing BST(Generally in VS code, Red-Black Tree is used) - Time complexity of all operations is O(logn) - <map>
2. Unordered Map - uses HashTable - Time Complexity of all operations is O(1) - <unordered_map>
*/