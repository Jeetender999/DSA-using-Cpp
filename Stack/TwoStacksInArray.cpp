#include <iostream>

using namespace std;

class TwoStackArray
{
    public :

    int cap;
    int top1;
    int top2;
    int* arr;

    TwoStackArray(int n)
    {
        cap = n;
        arr = new int[cap];
        fill(arr,arr+cap,INT_MIN);
        top1 =-1;
        top2 = cap;
      
    }

    void push1(int n);
    void push2(int n);
    int pop1();
    int pop2();

    void print()
    {
        for(int i=0;i<cap;i++)
        cout << arr[i] << " ";
    }

    
};

void TwoStackArray::push1(int n)
{

    if(top1 < top2-1)
   {
     top1++;
    arr[top1] = n;
   }
   
}

void TwoStackArray::push2(int n)
{

    if(top1 < top2-1)
   {
     top2--;
    arr[top2] = n;
   }
   
}

int TwoStackArray::pop1()
{
    if(top1 >= 0)
    {
        int x = arr[top1];
       top1--;
       return x;

    }
}

int TwoStackArray::pop2()
{
    if(top2 < cap)
    {
        int x = arr[top2];
       top2++;
       return x;

    }
}

int main()
{
    TwoStackArray ts(10);

    ts.push1(3);
    ts.push1(6);
    ts.push1(9);

    ts.push2(5);
    ts.push2(10);
    ts.push2(15);

    ts.print();

   
    
}