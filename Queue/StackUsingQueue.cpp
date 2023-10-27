#include <iostream>
#include <queue>

using namespace std;

class StackUsingQueue
{
  public :
  queue<int> q;
  int top;
  int size;

  StackUsingQueue()
  {
    size = 0;
    top = -1;
  }

  void push(int n);
  void pop();
  void print();
};

void StackUsingQueue::push(int n)
{
  queue<int> temp;

  while(q.empty() == false)
     {
        temp.push(q.front());
        q.pop();
     }

     q.push(n);
     top = q.front();

   while(temp.empty() == false)
     {
        q.push(temp.front());
        temp.pop();
     }

}

void StackUsingQueue::pop()
{
    q.pop();
    top = q.front();
    size--;
}

void StackUsingQueue::print()
{
    queue<int> temp = q;



    while(temp.empty() == false)
    {
        cout << temp.front() << " ";
        temp.pop();
    }
}

int main()
{
    StackUsingQueue sq;
    sq.push(3);
    sq.push(6);
    sq.push(9);
    sq.push(12);
    sq.pop();
    sq.pop();
    sq.print();
}

