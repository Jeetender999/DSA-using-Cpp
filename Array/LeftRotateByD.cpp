#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

void leftRotateByD(int arr[],int n,int D){
    D = D%n;
    vector<int> temp;
    vector<int>temp2;
    for(int i=0;i<D;i++)
        temp.push_back(arr[i]);

    for(int i = D;i<n;i++){
        temp2.push_back(arr[i]);
    }    

    for(auto x : temp){
        temp2.push_back(x);
    }

    for(auto x : temp2){
        cout << x << " ";
    }
}

void leftRotateByD2(int arr[],int n,int D){
    // Reversal Algorithm

   reverse(arr,arr+D);
   reverse(arr+D,arr+n);
   reverse(arr,arr+n);
}
int main(){
    int arr[] = {3,5,2,1,4};
    int n= sizeof(arr)/sizeof(arr[0]);
    leftRotateByD2(arr,n,2);

    for(auto x : arr){
        cout << x << " ";
    }
   
    
}