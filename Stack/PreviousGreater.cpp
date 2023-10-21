#include <iostream>
#include <stack>
using namespace std;


void previousGreaterArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        int prevLarge = -1;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j] > arr[i])
              {
                prevLarge = arr[j]; 
                break;
              } 
             
        }

        cout << prevLarge << " ";
    }
}

void previousGreater(int arr[], int n)
{
    stack<int> s;
    cout << -1 << " ";
    s.push(arr[0]);

    for(int i=1;i<n;i++)
    {
        while(s.empty() == false && s.top() <= arr[i])
         s.pop();
        
        int prevGrt = s.empty() ? -1 : s.top();
         cout << prevGrt << " ";

         s.push(arr[i]);
    }
}

int main()
{

    int arr[] = {20,30,10,5,15};
    int size = sizeof(arr)/sizeof(arr[0]);
    previousGreaterArray(arr,size);
    cout << endl;
    previousGreater(arr,size);

}