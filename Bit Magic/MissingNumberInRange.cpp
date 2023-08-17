#include<iostream>>

using namespace std;

//Program to find Missing number from given range

int missingNum(int arr[],int n){
      int res = 0;
        
        for(int i=0;i< n ;i++){
            res = res ^ arr[i];
        }

        for(int i=0;i<=n+1;i++){
            res = res^i;
        }
 
        return res;
}

int main(){
    int arr[] = {1,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << n << endl;

    cout << missingNum(arr,n) << endl;
}