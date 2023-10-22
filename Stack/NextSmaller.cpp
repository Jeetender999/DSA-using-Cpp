#include <iostream>
#include <stack>

using namespace std;

void nextSmallerArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        int nextSmaller = -1;

        for(int j=i+1;j<n;j++)
        {
            if(arr[j] < arr[i])
            {
                nextSmaller = arr[j];
                break;
            }
        }

        cout << nextSmaller << " ";
    }
}

void nextSmaller(int arr[], int n)
{
    stack<int> s;
    cout << -1 << " ";
    s.push(arr[n-1]);
    
    for(int i=n-2;i>=0;i--)
    {
        while(s.empty()==false && s.top() > arr[i])
        s.pop();


        int nextSmaller = s.empty() ? -1 : s.top();
        cout << nextSmaller <<  " ";
        s.push(arr[i]);

    }
}

int main()
{
   int arr[] = {6,2,5,4,1,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);

   nextSmallerArray(arr,n);
   cout << endl;
    nextSmaller(arr,n);
}