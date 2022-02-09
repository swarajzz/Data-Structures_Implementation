#include <iostream>
#include <climits>
using namespace std;

class StackusingArray
{
private:
    int *data;
    int capacity;
    int nextIndex;

public:
    StackusingArray(int totalSize)
    {
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }

    //Total number of elements in the stack
    int size()
    {
        return nextIndex;
    }

    //Check whether stack is empty or not
    bool isEmpty()
    {
        return nextIndex == 0;
    }

    //Insert into stack
    void push(int element)
    {
        if (capacity == nextIndex)
        {

            cout << "Stack Overflow" << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    // Delete and return the top element
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    //Return the Top element in the stack
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow";
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};
