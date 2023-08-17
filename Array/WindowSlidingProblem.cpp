#include<iostream>
#include <algorithm>

using namespace std;

int slidingWindow(int arr[],int n,int k){
    
    int res =0;
    for(int i=0;i<n-k+1;i++){
        int sum = 0;
        for(int j=i;j<i+k;j++){
           sum= sum+arr[j];
        }
        res = max(sum,res);
    }

    return res;
}

int windowSlidingTechnique(int arr[],int n,int k){
    int curr_sum =0;

    for(int i=0;i<k;i++)
     curr_sum += arr[i];  
     int max_sum = curr_sum;

    for(int i=1;i<n-k+1;i++){
       curr_sum += (arr[i+k-1] - arr[i-1]);
       max_sum = max(max_sum,curr_sum);
    }     

    return max_sum;
}
int main(){
     int arr[] = {1,8,30,-5,20,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int res = slidingWindow(arr,n,3);
    int res2 = windowSlidingTechnique(arr,n,3);
    cout << res2 << endl;
    cout << res << endl;
}