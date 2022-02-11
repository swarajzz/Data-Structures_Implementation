#include <iostream>
using namespace std;

template <typename T>
class QueueUsingArray
{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

public:
    //Constructor
    QueueUsingArray(int totalSize)
    {
        data = new T[totalSize];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = totalSize;
    }

    // Current size of the queue
    int getSize()
    {
        return size;
    }

    // Is empty?
    bool isEmpty()
    {
        return size == 0;
    }

    // Insert into queue
    void enqueue(T element)
    {
        if (size == capacity)
        {
            cout << "Queue Overflow!" << endl;
            return;
        }

        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if (firstIndex == -1)
        {
            firstIndex++;
        }
        size++;
    }

    // Remove and return the front element
    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!" << endl;
            return 0;
        }

        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        return ans;
    }

    // Earliest element
    T front()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!" << endl;
            return 0;
        }
        return data[firstIndex];
    }
};
