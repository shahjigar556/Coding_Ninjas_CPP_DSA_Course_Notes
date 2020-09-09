#include <string>
using namespace std;

template <typename V>
class MapNode {
    public:
        string key;
        V value;
        MapNode* next;

        MapNode(string key, V value) {
            this->key = key;
            this->value = value;
            next = nullptr;
        }
        ~MapNode() {
            delete next;
        }
};

template <typename V> 
class ourmap {
    // bucket array
    MapNode<V>* *buckets; // we are creating a 2-D array in heap of type MapNode<V>*
    int count;
    int numBuckets;

    public:
    ourmap() {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V>*[numBuckets];
        for(int i = 0; i < numBuckets; i++) {
            buckets[i] = nullptr;
        }
    }

    ~ourmap() {
        for(int i = 0; i < numBuckets; i++) {
            delete buckets[i];
        }
        delete[] buckets;
    }

    int size() {
        return count;
    }

    V getValue(string key) {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while(head != nullptr) {
            if(head->key == key) {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

    private:
    int getBucketIndex(string key) {
        int hashCode = 0;

        int currentCoeff = 1;
        // transform the string into a base of p to get the hashCode, where p is any prime number
        for(int i = key.length() - 1; i >= 0; i--) {
            hashCode += key[i] * currentCoeff;
            // to make sure that our hashCode does not go out of range, so,
            hashCode = hashCode % numBuckets; // property of modulus is to keep things in a particular a
            currentCoeff *= 37; // 37 is p here
            // to make sure that our currentCoeff does not go out of range, so,
            currentCoeff = currentCoeff % numBuckets; // through modular operator, we make sure that currentCoef
        }

        return hashCode % numBuckets;
    }

    void rehash() {
        MapNode<V>** temp = buckets;
        buckets = new MapNode<V>*[2 * numBuckets];
        for(int i = 0; i < 2*numBuckets; i++) {
            buckets[i] = nullptr;
        }
        int oldBucketCount = numBuckets;
        numBuckets *= 2;
        count = 0;
        for(int i = 0; i < oldBucketCount; i++) {
            MapNode<V>* head = temp[i];
            while(head != nullptr) {
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }
        for(int i = 0; i < oldBucketCount; i++) {
            MapNode<V>* head = temp[i];
            delete head;
        }
        delete[] temp;
    }

    public:
    double getLoadFactor() {
        return (1.0*count)/numBuckets;
    }

    void insert(string key, V value) {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex]; // linkedlist corresponding to the buckedIndexth element in buckets array in heap
        while(head != nullptr) {
            if(head->key == key) {
                head->value = value;
                return;
            }
            head = head->next;
        }
        MapNode<V>* node = new MapNode<V>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;
        double loadFactor = (1.0*count)/numBuckets;
        if(loadFactor > 0.7) {
            rehash();
        }
    }

    V remove(string key) {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex]; // buckets is pointing to the array in heap, so it's a pointer
        MapNode<V>* prev = nullptr;
        while(head != nullptr) {
            if(head->key == key) {
                if(prev == nullptr) {
                    buckets[bucketIndex] = head->next; 
                    // now the bucketIndexth element in the buckets array in heap is pointing towards head->next
                } else {
                    prev->next = head->next;
                }
                V value = head->value;
                head->next = nullptr;
                // we need to make the next nullptr. Because we defined the destructor recusive. 
                // So, if head is deleted, the whole linkedlist will be deleted
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }

};