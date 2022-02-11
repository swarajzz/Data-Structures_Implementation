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
    QueueUsingArray(int totalSize)
    {
        data = new T[totalSize];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = totalSize;
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

int main()
{
    QueueUsingArray<int> q(5);

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