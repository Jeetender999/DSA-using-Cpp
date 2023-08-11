#include<iostream>

using namespace std;

void reverse(int arr[], int n){

    for(int i=0, j=n-1; i<=j;i++,j--){
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}
int main(){

  int arr[] = {3,5,9,4};
  int n = sizeof(arr)/sizeof(arr[0]);

  cout << "Orignal Array " << endl;
 for(auto x : arr){
    cout << x << " ";
  }
  cout << endl;

  reverse(arr,n);

cout << "Reversed Array " << endl;
  for(auto x : arr){
    cout << x << " ";
  }
}