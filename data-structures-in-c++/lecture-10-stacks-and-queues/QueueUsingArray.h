#include <iostream>
using namespace std;

/***********************************************************************************************************************
 * Static Queue
 */
/*
template <typename T>

class QueueUsingArray
{
    T *data;
    int nextIndex;  // Initiate with 0
    int firstIndex; // Initiate with -1
    int size;
    int capacity; // capacity of the queue

public:
    QueueUsingArray(int s)
    {
        data = new T[s];
        firstIndex = -1;
        nextIndex = 0;
        size = 0;
        capacity = s;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void enqueue(T element)
    {
        if (size == capacity)
        {
            cout << "Queue is full!" << endl;
        }
        else
        // if (size != capacity)
        {
            if (firstIndex == -1)
            {
                firstIndex = 0;
            }
            data[nextIndex] = element;
            nextIndex = (nextIndex + 1) % capacity;
            // In this way if the nextIndex reaches the end of the array then it will become zero and continue to add elements
            // for capacity = 5, if nextIndex reached 4 then after enque, it will be updated to (4 + 1) % 5 and become 0.
            size++;
        }
    }
    T front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return 0;
        }
        return data[firstIndex];
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return 0;
        }
        size--;
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        // In this way if the firstIndex reaches the end of the array then it will become zero and continue to add elements
        // for capacity = 5, if firstIndex reached 4 then after enque, it will be updated to (4 + 1) % 5 and become 0.
        return ans;
    }
};
*/

/***********************************************************************************************************************
 * Dynamic Queue
 */
template <typename T>

class QueueUsingArray
{
    T *data;
    int nextIndex;  // Initiate with 0
    int firstIndex; // Initiate with -1
    int size;
    int capacity; // capacity of the queue

public:
    QueueUsingArray(int s)
    {
        data = new T[s];
        firstIndex = -1;
        nextIndex = 0;
        size = 0;
        capacity = s;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void enqueue(T element)
    {
        if (size == capacity)
        {
            T *newData = new T[2 * capacity];
            int j = 0;
            for (int i = firstIndex; i < capacity; i++) // if firstIndex != 0
            {
                newData[j] = data[i];
                j++;
            }
            for (int i = 0; i < firstIndex; i++)
            {
                newData[j] = data[i];
                j++;
            }
            delete data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
        }
        if (firstIndex == -1)
        {
            firstIndex = 0;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        // In this way if the nextIndex reaches the end of the array then it will become zero and continue to add elements
        // for capacity = 5, if nextIndex reached 4 then after enque, it will be updated to (4 + 1) % 5 and become 0.
        size++;
    }
    T front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return 0;
        }
        return data[firstIndex];
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return 0;
        }
        size--;
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        // In this way if the firstIndex reaches the end of the array then it will become zero and continue to add elements
        // for capacity = 5, if firstIndex reached 4 then after enque, it will be updated to (4 + 1) % 5 and become 0.
        return ans;
    }
};
