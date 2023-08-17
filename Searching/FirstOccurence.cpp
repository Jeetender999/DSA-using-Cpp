#include <iostream>

using namespace std;

int firstOccurence(int arr[],int n,int ele){

    for(int i=0;i<n;i++){
        if(arr[i] == ele)
          return i;
    }

    return -1;
}

int firstOccRec(int arr[],int low,int high,int x){

    if(low>high)
     return -1;

     int mid = (low+high)/2;

    

     if(arr[mid] > x){
        high = mid-1;
        firstOccRec(arr,low,high,x);
     }
     else if(arr[mid] < x){
        low = mid+1;
         firstOccRec(arr,low,high,x);
     }
     else{
        if(mid==0 || arr[mid]!=arr[mid-1])
         return mid;
        else
         firstOccRec(arr,low,mid-1,x);
     }
}

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

int main(){
    int arr[] = {0,1,1,2,3,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << firstOccurence(arr,n,8) << endl;
   cout << firstOccRec(arr,0,n-1,8) << endl;
   cout << firstOcc(arr,n,8) << endl;

}