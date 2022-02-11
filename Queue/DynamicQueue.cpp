#include <iostream>
using namespace std;

template <typename T>
class DynamicQueue
{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

public:
    // Constructor
    DynamicQueue(int totalSize)
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
            T *newData = new T[capacity * 2];
            int j = 0;
            for (int i = firstIndex; i < capacity; i++)
            {
                newData[j++] = data[i];
            }
            for (int i = 0; i < nextIndex; i++)
            {
                newData[j++] = data[i];
            }

            delete[] data;
            data = newData;
            nextIndex = size;
            firstIndex = 0;
            capacity *= 2;
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

int main(){
    DynamicQueue<int> q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;

}
