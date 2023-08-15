#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

int trappingRainWater(int arr[],int n){

    int res =0;

    for(int i=0;i<n;i++){

        int lmax = arr[i];
        for(int j=0;j<i;j++){
            lmax = max(lmax,arr[j]);
        }

        int rmax = arr[i];

        for(int j=i+1;j<n;j++){
        rmax = max(rmax,arr[j]);
        }

       res = res + (min(lmax,rmax) - arr[i]);
    }

    return res;
}


int getWater(int arr[], int n){
    int res = 0;
    
    int lmax[10];
    int rmax[10];

    lmax[0] = arr[0];

    for(int i=1;i<n;i++){
        lmax[i] = max(arr[i],lmax[i-1]);
    }

    rmax[n-1] = arr[n-1];

    for(int i = n-2;i>=0;i--){
        rmax[i] = max(arr[i],rmax[i+1]);
    }

    for(int i=1;i<n-1;i++){
        res = res + (min(lmax[i],rmax[i])-arr[i]);
    }

    return res;

}
int main(){
     int arr[] = {5,0,6,2,3};
   
    int n= sizeof(arr)/sizeof(arr[0]);

    int res = trappingRainWater(arr,n);
    int res2 = getWater(arr,n);
    
    cout << res << endl;
        cout << res2 << endl;
 
}