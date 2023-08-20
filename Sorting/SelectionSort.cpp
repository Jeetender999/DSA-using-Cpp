#include <iostream>

using namespace std;

void selectionSort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[j] < arr[i]){
                swap(arr[j],arr[i]);
            }
        }
    }
}

int main()
{
    int arr[] = {10,5,8,20,2,18};
    int n= sizeof(arr)/sizeof(arr[0]);

    for(auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

   
    selectionSort(arr,n);
    for(auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}