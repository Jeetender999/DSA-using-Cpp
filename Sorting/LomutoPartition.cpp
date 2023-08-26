#include <iostream>
using namespace std;

int lomutoPartition(int arr[],int l,int h)
{
    int pivot = arr[h];
    int i= l-1;

    for(int j=0;j<=h-1;j++)
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

int main()
{
    int arr[] = {5,10,1,3,12,6};
    int n= sizeof(arr)/sizeof(arr[0]);

    for(auto x : arr)
    {
        cout <<  x << " ";
    }

  cout << endl;
   int res = lomutoPartition(arr,0,n-1);

     for(auto x : arr)
    {
        cout <<  x << " ";
    }

  cout << endl << "Index of pivot after partition : " << res ;
}