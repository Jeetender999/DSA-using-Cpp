#include <iostream>

using namespace std;

int hoarePartition(int arr[],int l,int h)
{
    int pivot = arr[l];
    int i = l-1;
    int j = h+1;

    while(true)
    {
        
        do{
            i++;
        }while(arr[i] < pivot);

       
        do{
            j--;
         } while(arr[j] > pivot);
        
        if(i>=j) return j;

        swap(arr[i],arr[j]);

    }
}

void quickSortHoare(int arr[],int l,int h)
{
    if(l<h)
    {
        int p = hoarePartition(arr,l,h);
        quickSortHoare(arr,l,p);
        quickSortHoare(arr,p+1,h);
    }
}
int main()
{
   int arr[] = {5,3,6,8,1,2};
   int n= sizeof(arr)/sizeof(arr[0]);


   quickSortHoare(arr,0,n-1);

   for(auto x : arr)
   {
    cout << x << " ";
   }
}