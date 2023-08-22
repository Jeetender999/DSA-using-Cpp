#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void mergeSortNaive(int arr1[], int arr2[],int n1,int n2)
{  
    // Naive Approact to sort to sorted arrays
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

   int n1 = mid-low+1;
   int n2 = high - mid;

int* left = new int[n1];
   int* right = new int[n2];
  
   for(int i=0;i<n1;i++)
   {
    left[i] = arr[low+i];
   }

   for(int i=0;i<n2;i++)
   {
    right[i] = arr[i+n1];
   }

   int i=0,j=0,k=0;
   while(i < n1 && j < n2)
   {
       if(left[i] <= right[j])
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

   while(i<n1)
   {
    arr[k] = left[i];
        k++;
    i++;
   }

   while(j<n2)
  {
     arr[k] = right[j];
        k++;
     j++;
  }
}


int main()
{
   
    int arr3[] = {1,3,5,7,1,2,4,6,10,12};
    int n3= sizeof(arr3)/sizeof(arr3[0]);
    
    mergeFunction(arr3,0,3,n3-1);
   
    for(auto x : arr3)
    {
        cout << x << " ";
    }
    cout << endl;


    
}