// We can't include main() in a header file

/***********************************************************************************************************************
 * Static Stack
 */
/*
#include <climits>

class StackUsingArray
{
    int *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray(int totalSize)
    {
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }

    // return the number of elements present in my stack
    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        // if(nextIndex == 0) {
		// 	return true;
		// }
		// else {
		// 	return false;
		// }
		
        return nextIndex == 0;
    }

    // insert element
    void push(int element)
    {
        if (nextIndex == capacity)
        {
            cout << "Stack full " << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    // delete element
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty " << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty " << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};
*/

/*************************************************************************************************************
 * Dynamic Stack
 */
/*
#include <climits>

class StackUsingArray
{
    int *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray()
    {
        capacity = 4;
        data = new int[capacity];
        nextIndex = 0;
    }

    // return the number of elements present in my stack
    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {

        // if(nextIndex == 0) {
        // 	return true;
        // }
        // else {
        // 	return false;
        // }

        return nextIndex == 0;
    }

    // insert element
    void push(int element)
    {
        if (nextIndex == capacity)
        {
            int *newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    // delete element
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty " << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty " << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};
*/

/***********************************************************************************************************************
 * Stack using Template
 */

#include <climits>

template <typename T>

class StackUsingArray
{
    T *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray()
    {
        capacity = 4;
        data = new T[capacity];
        nextIndex = 0;
    }

    // return the number of elements present in my stack
    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {

        // if(nextIndex == 0) {
        // 	return true;
        // }
        // else {
        // 	return false;
        // }

        return nextIndex == 0;
    }

    // insert element
    void push(T element)
    {
        if (nextIndex == capacity)
        {
            T *newData = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    // delete element
    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty " << endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty " << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }
};
