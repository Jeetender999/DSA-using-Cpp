#include <iostream>

using namespace std;

int maxSum(int arr[], int n){

    int maxSum = arr[0];

    for(int i=0;i<n;i++){

        int curSum = 0;
        for(int j=i;j<n;j++){
         curSum = curSum+arr[j];
         maxSum = max(maxSum,curSum);
        }
    }

    return maxSum;
}

int maximumSum(int arr[], int n){
    int maxSum = arr[0];
    int maxEnding = arr[0];

    for(int i=1;i<n;i++){
        maxEnding = max(maxEnding+arr[i], arr[i] );
        maxSum = max(maxEnding, maxSum);

    }

    return maxSum;
}

int main(){
     int arr[] = {5,-1,-8,3,10};
    int n= sizeof(arr)/sizeof(arr[0]);
    int res = maxSum(arr,n);
    int res2  = maximumSum(arr,n);
    cout << res << endl;
    cout << res2<<endl;
}