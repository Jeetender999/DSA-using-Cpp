#include <iostream>

using namespace std;

int binarySearch(int arr[],int n, int ele){

    int start = 0;
    int end = n-1;
    int mid = (start+end)/2;
    cout << "Mid is " << mid << endl;
    for(int i=0; start <= end;i++){

         mid = (start+end)/2;
          cout << "Mid is " << mid << endl;
        if(arr[mid] == ele)
          return mid;

        if(arr[mid]>ele)
         end = mid-1;

         if(arr[mid]<ele)
         start = mid+1;

             
    }

    return -1;
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
   
    cout << binarySearch(arr,n,1) << endl;
    
    return 0;

}