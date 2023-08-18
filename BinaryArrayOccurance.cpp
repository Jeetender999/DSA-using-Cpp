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

int countOnes(int arr[], int n){
    int first = firstOcc(arr,n,1);

    if(first == -1)
      return 0;

    return (n-first);
}

int count1s(int arr[],int n){

    int low=0, high = n-1;

    while(low <= high){

        int mid = (low+high)/2;

        if(arr[mid] == 0)
          low = mid+1;
        else{
            if(mid == 0 || arr[mid-1]==0)
             return (n-mid);
            else 
             high = mid-1;
             
        }
    }
}
int main(){
    int arr[] = {1,1,1,1,1};
     int n = sizeof(arr)/sizeof(arr[0]);
     cout << countOnes(arr,n) << endl;
     cout << count1s(arr,n) << endl;
}