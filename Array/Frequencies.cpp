#include <iostream>
#include <algorithm>

using namespace std;

void frequencies(int arr[], int n){

    for(int i=0;i<n;i++){
        int count = 0;
        for(int j=0;j<n;j++)
        {
            if(arr[j] == arr[i])
             count++;
        }

        cout << arr[i] << " " << count << endl;
    }
}

void frequencySorted(int arr[],int n){
    int freq =1, int i=1;
    while(i<n){
        while(i<n && arr[i] == arr[i-1]){
            freq++;
            i++;
        }

        cout << arr[i-1] << " " << freq << endl;
        i++;
        freq =1;
    }

    if(n==1 || arr[n-1] != arr[n-2]){
        cout << arr[n-1] << " " << 1 << endl;
    }
}

int main(){
    int arr[] = {3,5,2,3,1};
   
    int n= sizeof(arr)/sizeof(arr[0]);
     sort(arr,arr+n);
    frequencies(arr,n);
}