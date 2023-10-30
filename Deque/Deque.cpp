#include <iostream>
#include <deque>
#include <list>


using namespace std;

int main()
{
    deque<int> dq = {3,6,9};

  
    
    dq.push_front(1);
    dq.push_back(10);
      auto it = dq.end();
    
    
   for(auto x : dq)
     cout << x << " ";

   cout << endl << *it << endl;
}