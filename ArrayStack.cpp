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
        if (capacity == nextIndex)
        {

            cout << "Stack Overflow" << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

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

int main()
{
    // cout << "Hello" << endl;
    StackusingArray s(4);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    // cout << s.top() << endl;
    // cout << s.pop() << endl;
    // cout << s.pop() << endl;
    // cout << s.pop() << endl;

    // cout << s.size() << endl;

    // cout << s.isEmpty() << endl;

    while (!s.isEmpty())
    {
    cout << s.pop() << endl;
    }
}