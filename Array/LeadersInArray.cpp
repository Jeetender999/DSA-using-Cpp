
#include <iostream>

using namespace std;

void leaders(int arr[],int n){


    for(int i=0;i<n;i++){
        bool isLeader = true;
        for(int j=i+1;j<n;j++){
           if(arr[j]>=arr[i])
            isLeader = false;
            break;
        }

        if(isLeader) cout << arr[i] << " ";
    }
}

void leaders2(int arr[], int n){
    int cur_lead = arr[n-1];
    cout << cur_lead << " ";

    for(int i=n-2; i>=0;i--){
        if(arr[i] > cur_lead)
        {
            cur_lead = arr[i];
            cout << cur_lead << " ";
        }
    }
}
int main(){
    int arr[] = {3,5,2,3,1};
    int n= sizeof(arr)/sizeof(arr[0]);

    leaders(arr,n);
    cout << "\n";
    leaders2(arr,n);
}