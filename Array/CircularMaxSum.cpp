#include <iostream>

using namespace std;

int maxSumCircular(int arr[], int n){
   
    int res = arr[0];
    for(int i=0;i<n;i++){
        int currMax = arr[i];
        int currSum = arr[i];
       for(int j=1;j<n;j++){
          int index = (i+j)%n;
          currSum = currSum+ arr[index];
          currMax = max(currMax,currSum);
       }

       res = max(res,currMax);
    }

    return res;
}
int main(){
     int arr[] = {5,-2,3,4};
    int n= sizeof(arr)/sizeof(arr[0]);

    int res = maxSumCircular(arr,n);
    cout << res << endl;
}