#include <iostream>
#include <stack>

using namespace std;

void nextGreaterArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        int nextGrt = -1;

        for(int j=i+1;j<n;j++)
        {
            if(arr[j] > arr[i])
             {
                nextGrt = arr[j];
                break;
             }
        }

        cout << nextGrt << " ";
    }
}

void nextGreater(int arr[], int n)
{
    stack<int> s;
    stack<int> print;
    print.push(-1);
    s.push(arr[n-1]);

    for(int i=n-2;i>=0;i--)
    {
        while(s.empty() == false && s.top() <= arr[i])
         s.pop();

        int nextGrt = s.empty() ? -1 : s.top();
        print.push(nextGrt);

        s.push(arr[i]); 
    }

    while(print.empty() == false)
    {
        cout << print.top() << " ";
        print.pop();
    }
}

int main()
{
    int arr[] = {5,15,10,8,6,12,9,18};
    int size = sizeof(arr)/sizeof(arr[0]);
    nextGreaterArray(arr,size);
    cout << endl;
    nextGreater(arr,size);
}