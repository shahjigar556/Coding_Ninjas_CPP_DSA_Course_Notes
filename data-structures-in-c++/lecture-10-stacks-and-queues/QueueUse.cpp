#include <iostream>
#include <queue>
// #include "QueueUsingArray.h"
// #include "QueueUsingLL.h"
using namespace std;

int main()
{
    // QueueUsingArray<int> q(5);
    // QueueUsingLL<int> q;
    /*
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // Queue is full!

    cout << q.front() << endl;   // 10
    cout << q.dequeue() << endl; // 10 will be deleted
    cout << q.dequeue() << endl; // 20 will be deleted
    cout << q.dequeue() << endl; // 30 will be deleted

    cout << q.getSize() << endl; // 2
    cout << q.isEmpty() << endl; // as size != 0, so false will be returned and will be interpreted as 0.
    */

    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    cout << q.front() << endl; // 10 <== enqueue
    q.pop();                   // 10 is removed <== dequeue
    cout << q.front() << endl; // 20
    cout << q.size() << endl;  // 5
    cout << q.empty() << endl; // false -> 0

    while (!q.empty())
    {
        cout << q.front() << " "; // 20 30 40 50 60
        q.pop();
    }
    cout << endl;
}