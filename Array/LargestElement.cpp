#include <iostream>

using namespace std;

int largestElement(int arr[], int n){
    
    int lar = 0;
  
    for(int i=0;i<n;i++){
        if(arr[i] > lar){
            lar = arr[i];
        }
    }
    return lar;
}
int main(){
    int arr[] = {34,2,3,55,2,35,22};
    int n = sizeof(arr)/sizeof(arr[0]);
   cout << "Hello Worlld" << endl;
    int lar = largestElement(arr,n);
    cout << lar << endl;
}