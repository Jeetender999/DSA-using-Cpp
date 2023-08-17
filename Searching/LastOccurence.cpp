

#include <iostream>

using namespace std;

int lastOccurence(int arr[],int n,int ele){

    for(int i=n-1;i>=0;i--){
        if(arr[i] == ele)
          return i;
    }

    return -1;
}

int lastOccRec(int arr[], int n, int low,int high,int x){

    if(low>high)
     return -1;

     int mid = (low+high)/2;

    

     if(arr[mid] > x){
        high = mid-1;
        lastOccRec(arr,n,low,high,x);
     }
     else if(arr[mid] < x){
        low = mid+1;
         lastOccRec(arr,n,low,high,x);
     }
     else{
        if(mid== n-1 || arr[mid]!=arr[mid+1])
         return mid;
        else
         lastOccRec(arr,n,mid+1,high,x);
     }
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

int main(){
    int arr[] = {5,10,10,10,10,20,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << lastOccurence(arr,n,10) << endl;
    cout << lastOccRec(arr,n,0,n-1,10) << endl;
     cout << lastOcc(arr,n,10) << endl;

}

