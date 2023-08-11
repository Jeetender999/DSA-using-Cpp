#include <iostream>

using namespace std;

int secondLargestElement(int arr[], int n){
    
    int lar1 = 0;
    int lar2 = -1;
  
    for(int i=1;i<n;i++){
        if(arr[i] > arr[lar1]){
            lar2 = lar1;
            lar1 = i;   
        }
        else if(arr[i] != arr[lar1]){
             if(lar2 == -1 || arr[i] > arr[lar2])
                lar2 = i;
        }
    }
    return lar2;
}
int main(){

    // Program to find second largest element in an array
    int arr[] = {10,10,10};
    int n = sizeof(arr)/sizeof(arr[0]);

    
    int lar2 = secondLargestElement(arr,n);
    if(lar2 != -1)
    cout << "Second largest Element is " <<  arr[lar2] << endl;
    else
      cout << lar2 << endl;
}