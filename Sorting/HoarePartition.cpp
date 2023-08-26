#include <iostream>
using namespace std;

int hoarePartition(int arr[],int low,int high)
{
    int pivot = arr[low];
    int i=low-1;
    int j = high+1;

    while(true)
    {
        do{
            i++;
        }while(arr[i] < pivot);

        do{
            j--;
        }while(arr[j]>pivot);

        if(i>=j) return j;

        swap(arr[i],arr[j]);
    }
}
int main()
{
    int arr[] = {10,1,3,5,12,6};
    int n= sizeof(arr)/sizeof(arr[0]);

    for(auto x : arr)
    {
        cout <<  x << " ";
    }

  cout << endl;
    int res = hoarePartition(arr,0,n-1);

     for(auto x : arr)
    {
        cout <<  x << " ";
    }

}