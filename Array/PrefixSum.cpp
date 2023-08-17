#include <iostream>
#include <vector>

using namespace std;

int prefixSum(int arr[],int n){
    int sum = arr[0];
    vector<int> v;
    v.push_back(arr[0]);

    for(int i=1;i<n;i++){
        sum = sum+arr[i];
        v.push_back(sum);
    }

    for(auto x : v){
        cout << x << " ";
    }
}

int main(){
     int arr[] = {2,8,3,9,6,5,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    prefixSum(arr,n);
}