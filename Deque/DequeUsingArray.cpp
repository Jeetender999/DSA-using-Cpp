#include <iostream>
#include <stack>

using namespace std;

class Deque
{
public:
    int *arr;
    int cap;
    int size;

    Deque(int n)
    {
        cap = n;
        arr = new int[n];
        size = 0;
    }

    void pushFront(int n);
    void pushRear(int n);

    int getFront() { return arr[0]; }
    int getRear() { return arr[size - 1]; }
    int getSize() { return size; }
    bool isEmpty() { return (size == 0); }
    bool isFull() { return (size == cap); }

    int popFront();
    int popRear();

    void print();
};

void Deque::pushFront(int n)
{

    for (int i = size; i >= 0; i--)
    {

        arr[i] = arr[i - 1];
    }
    arr[0] = n;
    size++;
}

void Deque::pushRear(int n)
{

    arr[size] = n;
    size++;
}

int Deque::popFront()
{
    int curr = arr[0];
    for(int i=0;i<size;i++)
    {
        arr[i] = arr[i+1];
    
    }
    size--;

    return curr;
}

int Deque::popRear()
{
    int curr = arr[size-1];
    size--;
    return curr;
}

void Deque::print()
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int main()
{
    Deque q(6);
    q.pushFront(3);
    q.pushFront(6);
    q.pushFront(1);

    q.pushRear(99);
    q.popFront();
    q.popRear();

    q.print();
    cout << endl;
    cout << q.getFront() << " " << q.getRear() << endl;
}