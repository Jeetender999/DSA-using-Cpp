#include <iostream>
#include <stack>

using namespace std;

void myPrint(stack<int> ms, stack<int> as)
{

    while(ms.empty() == false)
    {
        cout << ms.top() << " ";
        ms.pop();
    }

    cout << endl;

    while(as.empty() == false)
    {
        cout << as.top() << " ";
        as.pop();
    }


}

class MyStack
{
  public : 

  stack<int> ms;
  stack<int> as;

  MyStack()
  {

  }

  void push(int n);
  void pop();

  void print()
  {
   myPrint(ms,as);
  }

};

void MyStack::push(int n)
{
    

    ms.push(n);

    if(as.empty())
    {
         as.push(n);
         return;
    }

    if(ms.top() <= as.top())
     as.push(n);
}

int main()
{

    MyStack s;

    s.push(5);
    s.push(10);
    s.push(3);
    s.push(25);

    
    s.print();


}