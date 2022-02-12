#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    Node<T> *next;
    T data;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class QueueLL
{
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    QueueLL()
    {
        head = NULL;
        tail = NULL;
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

    void enqueue(T element)
    {
        Node<T> *newNode = new Node<int>(element);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        size++;
    }

    T front()
    {
        if (isEmpty())
        {
            return 0;
        }
        return head->data;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            return 0;
        }
        Node<T> *temp = head;
        T ans = temp->data;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }
};
