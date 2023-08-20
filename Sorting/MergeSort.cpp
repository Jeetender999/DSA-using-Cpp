#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void mergeSort(int arr1[], int arr2[],int n1,int n2)
{
    vector<int> v;

    for(int i=0;i<n1;i++)
    {
        v.push_back(arr1[i]);
    }

    for(int i=0;i<n2;i++)
    {
        v.push_back(arr2[i]);
    }

    for(int i=0;i<v.size();i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

   sort(v.begin(),v.end());

   for(int i=0;i<v.size();i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

}

void mergeSortPrintTwoArrays(int arr1[],int arr2[],int n1,int n2)
{
    int i=0, j=0;

    while(i<n1 && j<n2)
    {
        if(arr1[i] <= arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
        }
        else{
            cout << arr2[j] << " ";
            j++;
        }
    }


    while(i<n1)
    {
        cout << arr1[i] << " ";
        i++;
    }

    while(j<n2)
    {
        cout << arr2[i] << " ";
        j++;
    }
}

void mergeFunction(int arr[],int low,int mid,int high)
{
   vector<int> left;
   vector<int> right;
   vector<int> res;

   for(int i=low;i<=mid;i++)
   {
    left.push_back(arr[i]);
   }

   for(int i=mid+1;i<=high;i++)
   {
    right.push_back(arr[i]);
   }

   int i=0,j=0,k=0;
   while(i < left.size() && j < right.size())
   {
       if(left[i] < right[j])
       {
        arr[k] = left[i];
        k++;
        i++;
       }
       else{
        arr[k] = right[j];
        k++;
        j++;
       }
   }

   while(i<left.size())
   {
    arr[k] = left[i];
        k++;
    i++;
   }

   while(j<right.size())
  {
     arr[k] = right[j];
        k++;
     j++;
  }
}

void mergeSortFull(int arr[],int left,int right)
{
    if(right > left)
    {
        int mid = left + (right-left)/2;
        mergeSortFull(arr,left,mid);
        mergeSortFull(arr,mid+1,right);
        mergeFunction(arr,left,mid,right);
    }
}
int main()
{
    int arr1[] = {2,4,6,8,10};
    int n1= sizeof(arr1)/sizeof(arr1[0]);

     int arr2[] = {1,3,5,7,9,11};
    int n2= sizeof(arr2)/sizeof(arr2[0]);

    int arr3[] = {1,3,5,7,1,2,4,6,10,12};
    int n3= sizeof(arr3)/sizeof(arr3[0]);

    mergeSortFull(arr3,0,n3-1);
    for(auto x : arr3)
    {
        cout << x << " ";
    }
    cout << endl;


    
}