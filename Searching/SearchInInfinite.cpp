#include <iostream>

using namespace std;

int search(int arr[],int n,int x)
{
    int i=0;
    for(i=0;arr[i] <= x;i++){
        if(arr[i] == x)
         return i;
        
    }

  return -1;

}

int searchInfinite(int arr[],int ele){
    
    if(arr[0]== ele)
      return 0;

    int i=1;
    while(arr[i] < ele){
         i= i*2;
        if(arr[i] == ele)
         return i;
    }  

    int low = i/2, high =i;

    while(low<=high){

      int mid =(low+high)/2;

      if(arr[mid] == ele)
        return mid;
      else if(arr[mid]>ele)
       high = mid-1;
      else if(arr[mid] < ele)
       low = mid+1;
    }

 return -1;

}
int main(){
    int arr[] = {5,10,10,10,10,15,20,30};
     int n = sizeof(arr)/sizeof(arr[0]);

     cout << searchInfinite(arr,10) << endl;

}