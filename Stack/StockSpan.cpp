#include <iostream>
#include <stack>

using namespace std;


void stockSpanArray(int arr[], int size)
{
     for(int i=0;i<size;i++)
    {
        int span=1;
        for(int j=i-1;j>=0 && arr[j] <= arr[i];j--)
        {
            span++;
        }

        cout << span << " ";
    }
}


void stockSpan(int arr[], int n)
{
    stack<int> s;
    s.push(0);
    cout << 1 << " ";

    for(int i=1;i<n;i++)
    {
        while(s.empty() == false && arr[s.top()] <= arr[i])
        s.pop();

     int span = s.empty() ?  i+1 : i-s.top();
     cout << span << " ";
     s.push(i);
    }
}

int main()
{
    int arr[] = {13,15,12,14,16,8,6,4,10,30};
    int size = sizeof(arr)/sizeof(arr[0]);

    stockSpanArray(arr,size);
    cout << endl;
    stockSpan(arr,size);

   
} 