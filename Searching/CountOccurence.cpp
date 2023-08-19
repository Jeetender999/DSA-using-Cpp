#include <iostream>

using namespace std;

int firstOcc(int arr[],int n,int x){
    int low = 0;
    int high = n-1;

   

    while(low <= high){

       int mid = (low+high)/2;

        if(arr[mid] < x) 
         low = mid+1;
        else if(arr[mid] > x)
        high = mid-1;
        else{
            if(arr[mid] != arr[mid-1] || mid ==0)
             return mid;
            else 
               high = mid-1;
        }
    } 

    return -1;
}


int lastOcc(int arr[],int n,int x){
    int low = 0;
    int high = n-1;

   

    while(low <= high){

       int mid = (low+high)/2;

        if(arr[mid] < x) 
         low = mid+1;
        else if(arr[mid] > x)
        high = mid-1;
        else{
            if(arr[mid] != arr[mid+1] || mid == n-1)
             return mid;
            else 
               low = mid+1;
        }
    } 

    return -1;
}


int countOccurance(int arr[], int n, int k){

    int first = firstOcc(arr,n,k);
    if(first == -1)
      return 0;

    else 
      return (lastOcc(arr,n,k)-first+1);
}

int main(){
    int arr[] = {5,10,10,10,10,20,20};
     int n = sizeof(arr)/sizeof(arr[0]);

     cout << countOccurance(arr,n,20) << endl;
}