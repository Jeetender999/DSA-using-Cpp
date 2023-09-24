#include <iostream>

using namespace std;

int lomutoPartition(int arr[],int l,int h)
{
    int pivot = arr[h];
    int i=l-1;
    

    for(int j=l;j<=h-1;j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1],arr[h]);

    return (i+1);
}

void quSort(int arr[],int l,int h)
{
    if(l<h)
    {
        int p = lomutoPartition(arr,l,h);
        quSort(arr,l,p-1);
        quSort(arr,p+1,h);
    }
}

int main()
{
    int arr[] = {5,10,1,3,12,6,7,7,10,0};
    int n= sizeof(arr)/sizeof(arr[0]);

     quSort(arr,0,n-1);
    for(auto x : arr)
    cout << x << " ";

   
}