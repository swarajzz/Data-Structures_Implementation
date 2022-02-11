#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class StackUsingList
{
    Node<T> *head;
    int size;

public:
    StackUsingList()
    {
        head = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void push(T element)
    {
        Node<T> *newNode = new Node<T>(element);
        newNode->next = head;
        head = newNode;
        size++;
    }

    T pop()
    {
        if (head == NULL)
        {
            cout << "Stack UnderFlow" << endl;
            return 0;
        }
        Node<T> *temp = head;
        head = head->next;
        T ans = temp->data;
        delete temp;
        size--;
        return ans;
    }

    T top()
    {
        if (head == NULL)
        {
            cout << "Stack UnderFlow" << endl;
            return 0;
        }
        return head->data;
    }
};

int main()
{
    StackUsingList<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << s.top() << endl;

    while (!s.isEmpty())
    {
        cout << s.pop() << endl;
    }
    
    cout << s.getSize() << endl;
}