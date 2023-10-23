#include <iostream>
#include <stack>

using namespace std;

void previousSmallerArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        int prevSmaller = -1;
        for(int j=i;j>=0;j--)
        {
            if(arr[j] < arr[i])
           {
             prevSmaller = arr[j];
             break;
           }
        }
        cout << prevSmaller << " ";
    }
}

void previousSmaller(int arr[], int n)
{
    stack<int> s;
    cout << -1 << " ";
    s.push(arr[0]);

    for(int i=1;i<n;i++)
    {
        while(s.empty() == false && s.top() > arr[i])
         s.pop();

        int prevSmaller = s.empty() ? -1 : s.top();
        cout << prevSmaller << " ";
        s.push(arr[i]); 
    }
}


int main()
{
    int arr[] = {6,2,5,4,1,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);

   previousSmaller(arr,n);

}