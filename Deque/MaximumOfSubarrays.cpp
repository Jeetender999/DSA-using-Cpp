#include <iostream>
#include <deque>

using namespace std;

void maximumNaive(int arr[], int n, int k)
{
    for(int i=0;i<n-k+1;i++)
    {
        int maxEle = arr[i];
        for(int j=i+1;j<k+i;j++)
        {
         maxEle = max(arr[j], maxEle);
        }
        cout << maxEle << " ";
    }
}

void printMax(int arr[], int n, int k)
{
    deque<int> dq;
    for(int i=0;i<k;i++)
    {
        
        while(!dq.empty() && arr[i] >= arr[dq.back()])
         dq.pop_back();
          
          dq.push_back(i);    
        
    }

    for(int i=k;i<n;i++)
    {
       cout << arr[dq.front()] << " ";

       while(!dq.empty() && dq.front() <= i-k)
         dq.pop_front();

       while(!dq.empty() && arr[i] >= arr[dq.back()])  
        dq.pop_back();

        dq.push_back(i);
    }

   
   
}

int main()
{
 int arr[] = {2,8,5,12,15,7,6};
 int size = sizeof(arr)/sizeof(arr[0]);
printMax(arr,size,3);

}