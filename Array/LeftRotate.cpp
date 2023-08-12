#include <iostream>

using namespace std;

void leftRotate(int arr[], int n){

    int temp = arr[0];
    int i=0;

    for(i=0;i<n;i++){
        arr[i] = arr[i+1];
    }

    arr[i-1] = temp;
}

int main(){
  int arr[] = {1,2,3,5,3,2,5};
  int n = sizeof(arr)/sizeof(arr[0]);
  leftRotate(arr,n);

  for(auto x : arr){
    cout << x << " ";
  }
}