#include <iostream>

using namespace std;

void mergeFunction(int arr[],int low,int mid,int high)
{
    int n1 = mid-low+1;
    int n2 = high - mid;
    int* left = new int[n1];
    int* right = new int[n2];

    for(int i=0;i<n1;i++)
    {
        left[i] = arr[low+i];
    }

    

    for(int j=0;j<n2;j++)
    {
        right[j] = arr[mid+1+j];
    }

   

    int i=0,j=0,k=low;

    while(i<n1 && j<n2)
    {
        if(left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
            k++;
            
        }
        else{
            arr[k] = right[j];
            j++;
            k++;
        }
    
    }

    while(i<n1){
        arr[k] = left[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge(int arr[],int low,int high)
{
    if(low < high)
    {
int mid = (low+high)/2;
        merge(arr,low,mid);
        merge(arr,mid+1,high);
        mergeFunction(arr,low,mid,high);
    }


        
    
}
int main()
{

    int arr[]  = {5,3,5,10,35,0,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    merge(arr,0,n-1);

    for(auto x : arr) cout << x << " ";

}