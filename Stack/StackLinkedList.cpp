#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int n)
    {
        data = n;
        next = NULL;
    }
};

class MyStack
{
    Node *head;
    int size;

public:
    MyStack()
    {
        head = NULL;
        size = 0;
    }

    void push(int n);
    int pop();
    int peek();
    bool isEmpty();
    int Size() { return size; }

    void print();
};

void MyStack::push(int n)
{
    Node *newNode = new Node(n);
    newNode->next = head;

    head = newNode;
    size++;
}

int MyStack::pop()
{

    if (head == NULL)
    {
        cout << "Underflow" << endl;
        return INT_MAX;
    }
    Node *temp = head;
    int data = temp->data;
    head = head->next;
    delete temp;
    size--;

    return data;
}

int MyStack::peek()
{
    if (head == NULL)
        return INT_MAX;

    return head->data;
}

bool MyStack::isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}

void MyStack::print()
{
    if (head == NULL)
        return;

    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main()
{
    MyStack s;
    cout << endl
         << s.isEmpty() << endl;
    s.push(5);
    s.push(10);
    s.push(15);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    s.print();

    cout << endl
         << s.isEmpty();
}