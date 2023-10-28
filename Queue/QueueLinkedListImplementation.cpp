#include <iostream>

using namespace std;

class Node
{
    public :
    int data;
    Node* next;

    Node(int n)
    {
        data = n;
        next = NULL;
    }
};

class MyQueue
{
    Node* front;
    Node* rear;
    int size;

    public : 
    MyQueue()
    {
        front=NULL;
        rear=NULL;
        size = 0;
    }

    void enqueue(int n);
     int dequeue();
     int getSize(){return size;}
     bool isEmpty(){return (front == NULL);}
     int getFront(){return front->data;}
     int getRear(){return rear->data;}
    void printQueue();
};

void MyQueue::enqueue(int n)
{
    Node* newNode = new Node(n);
    size++;

    if(front == NULL && rear == NULL)
    {
       front = newNode;
       rear = newNode;
       return;
    }

    rear->next = newNode;
    rear = newNode;

}

int MyQueue::dequeue()
{
    if(front == NULL )
     return -1;

    size--;
    Node* temp = front;
    front = front->next;

    

    int data = temp->data;
    delete temp;
    
    if(front == NULL)
    {
        rear = NULL;
        
    }

    return data;

}

void MyQueue::printQueue()
{
    Node* curr = front;

    while(curr != NULL)
   {
     cout << curr->data << " ";
     curr = curr->next;
   }
}

int main()
{
  MyQueue q;
  cout << "Is empty " << q.isEmpty() << endl;
  q.enqueue(3);
  q.enqueue(6);
  q.enqueue(9);
  q.enqueue(99);
   cout << "Size " << q.getSize() << endl; 
   cout << "Is empty " << q.isEmpty() << endl;
  q.dequeue();
 
  q.printQueue();

  cout << endl;
  cout << "Front " << q.getFront() << endl;
  cout <<"Rear " << q.getRear() << endl;
}