#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void reserseQueue(queue<int> q)
{
     stack<int> s;

    while(q.empty() == false)
    {
        s.push(q.front());
        q.pop();
    }   

    while(s.empty() == false)
    {
        cout << s.top() << " ";
        s.pop();
    }
}

void iterativeReverse(queue<int> q)
{
    if(q.empty())
     return;

    int top = q.front();
    
    q.pop();
    iterativeReverse(q);
      cout << top << " "; 
      q.push(top);
  
}

int main()
{
    queue<int> q({3,6,9,10});
    iterativeReverse(q);
   
}