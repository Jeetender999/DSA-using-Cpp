#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(arr[j] > arr[j+1])
            swap(arr[j],arr[j+1]);
        }
    }
}

void bubbleSortOptimized(int arr[], int n)
{
   
    for(int i=0;i<n-1;i++)
    {
         bool swapped = false;
        for(int j=0;j<n-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }

        if(swapped == false)
         return;
    }
}

int main()
{
    int arr[] = {5,2,3,6,1,0,43,2,0};
    int n= sizeof(arr)/sizeof(arr[0]);

    for(auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    bubbleSortOptimized(arr,n);

    for(auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}