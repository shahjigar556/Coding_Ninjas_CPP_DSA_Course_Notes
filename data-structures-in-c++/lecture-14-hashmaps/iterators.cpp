#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int main() {
    unordered_map<string, int> ourmap;
    ourmap["abc"] = 1;
    ourmap["abc1"] = 2;
    ourmap["abc2"] = 3;
    ourmap["abc3"] = 4;
    ourmap["abc5"] = 6;

    // By using iterator, we kind of get pointer to a data member
    // by doing, it++ we can iterate through next elements
    // most STL have iterators 
    // Each STL have different kind of iterators. The iterators do the same work but how it does the work, is different.

    // Declaration of iterator:
    // STL_NAME<T,..>::iterator iterator_name
    // "STL_NAME<T,..>::iterator" is the data type of the iterator
    unordered_map<string, int>::iterator it; // Here we have the iterator in the unordered map
    
    // Get the first element of the urordered map. As, it is an unordered map so, we will get any one element
    it = ourmap.begin(); // ourmap.begin() returns a iteratorn to the first elemnt of ourmap

    // iterate to the next element
    // it++;

    // when we iterate through all elements and reach after the last element:
    // it = ourmap.end();

    // print all the elements using iterator:
    while(it != ourmap.end()) {
        // map is effectively a pair of key and value
        cout << "Key : " << it->first << " Value : " << it->second << endl; // (*it).first => it->first
        // The output will not be in particular order as we are using unordered map
        // But, if we had used ordered map, then it would print in sorted order
        it++;
    }

    // find
    unordered_map<string, int>::iterator it2 = ourmap.find("abc"); // it takes key and returns a iterator pointing to the key

    // erase
    // ourmap.erase(it2); // erase function takes iterators too instead of key
    /*
    We can not erase elements in a rango for any kind of map as they are bi directional.
    They only support it++ and it--
    It was suported in the previous versions of gcc
    But in the newer version, if we do want to use the ranged erase for bidirectional STL,
    then we need to provide two distinct iterators and not use it + n
    */    
//    ourmap.erase(it2, it2 + 3); // it2 + 3 is not supported
    unordered_map<string, int>::iterator it3 = ourmap.find("abc2");
    ourmap.erase(it2, it3); // This is allowed. We need to provide two distinct iterators

    // For vectors
    vector<int> v; // vector is ordered
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);

    // vector iterator
    vector<int>::iterator it1 = v.begin(); // it1 is pointing to the first element

    // erase in a range
    v.erase(it1 + 1, it1 + 4); // This will delete from it1 + 1 to it1 + 3
    
    // iterator is effectively a pointer
    while(it1 != v.end()) {
        cout << *it1 << endl;
        it1++;
    }

}