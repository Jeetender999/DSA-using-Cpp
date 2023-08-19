#include <iostream>

using namespace std;

int sortedAndRotated(int arr[], int n, int ele)
{

    int low = 0, high = n - 1;
    
    while(low<=high){

        int mid = (low+high)/2;
        
        if(arr[mid] == ele)
          return mid;
        
        if(arr[low]  <= arr[mid]){

            if(ele >= arr[low] && ele <arr[mid])
             high = mid-1;
            else 
               low = mid+1;

        }
        else
        {
            if(ele > arr[mid] && ele <= arr[high])
            low = mid+1;
            else
             high = mid-1;
        }
    }

    return -1;
}
int main()
{
    int arr[] = {3,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << sortedAndRotated(arr, n, 1);
}