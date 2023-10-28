#include <iostream>
#include <queue>



using namespace std;

class Queue
{
    public :

    int front;
    int rear;
    int* arr;
    int size;
    int cap;

    Queue(int n)
    {
        cap = n;
        arr = new int[cap];
        front = -1;
        rear = -1;
        size = 0;
    }

    void enqueue(int n);
    int dequeue();
    int getSize(){return size;};
    int getFront(){return arr[front];};
    int getBack(){return arr[rear];};
    bool isFull(){return (size==cap);};
    bool isEmpty(){return (front==-1);};
    void printQueue();

    
};

void Queue::enqueue(int n)
{
    size++;
    if(front == -1)
    {
        front++;
        rear++;
        arr[rear] = n;
        return;
    }

    rear++;
    arr[rear]=n;
}

int Queue::dequeue()
{
    size--;
    int temp = arr[front];
    front++;
    return temp;
}

void Queue::printQueue()
{
    
    for(int i=front;i<=rear;i++)
     cout << arr[i] << " ";

     

}

int main()
{
    
    Queue q(5);
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.dequeue();
    q.printQueue();
}