#include <iostream>
#include <climits>
#include <vector>
using namespace std;

template <typename T>
class DynamicStack
{
    T *data;
    int nextIndex;
    int capacity;

public:
    DynamicStack()
    {
        data = new T[4];
        nextIndex = 0;
        capacity = 4;
    }

    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    void push(int element)
    {
        if (nextIndex == capacity)
        {
            T *newData = new T[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newData;
        }
        data[nextIndex++] = element;
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }
};

int main()
{
    DynamicStack<int> s;

   s.push(1);
   s.push(2);
   s.push(3);
   s.push(4);

   cout << s.top() << endl;
   cout << s.pop() << endl;
   cout << s.top() << endl;
}