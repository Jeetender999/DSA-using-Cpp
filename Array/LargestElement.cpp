#include <iostream>

using namespace std;

int largestElement(int arr[], int n){
    
    int lar = 0;
  
    for(int i=0;i<n;i++){
        if(arr[i] > arr[lar]){
            lar = i;
        }
    }
    return lar;
}
int main(){
    int arr[] = {34,2,3,55,2,35,22,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    int lar = largestElement(arr,n);
    cout << arr[lar] << endl;
}