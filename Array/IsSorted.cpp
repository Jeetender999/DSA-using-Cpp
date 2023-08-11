#include <iostream>

using namespace std;

bool isSorted(int arr[], int n){
  
  for(int i=0;i<n-1;i++){

    if(arr[i] > arr[i+1])
      return false;
  }

  return true;
}


int main(){

    int arr[] = {3,3,3};

    int n = sizeof(arr)/sizeof(arr[0]);

    bool res = isSorted(arr,n);

    if(res) cout << "Sorted";
    else cout << "Not sorted";

    

}