#include <iostream>

using namespace std;

int pairWithGivenSum(int arr[], int n,int k){
    for(int i=0;i<n;i++){
        int sum = 0;
 
        for(int j=i+1;j<n;j++){
            sum = arr[i] + arr[j];

            if(sum == k){
                
                cout << arr[i] << " " << arr[j] << endl;
            }
            
        }
        
    }
    return 0;
}

int twoPointerApproach(int arr[], int n,int k)
{
    int left = 0;
    int right = n-1;

    while(left < right){

        if(arr[left]+arr[right]==k)
          {
            cout << arr[left] << " " << arr[right] << endl;
            cout << arr[left] + arr[right] << endl;
            return 1;
          }

        if(arr[left]+arr[right] > k)
          right = right -1;

        if(arr[left] + arr[right] < k)
          left = left+1;  
    }

     cout << "No pair found" << endl;
    return -1;
}


int main(){
 int arr[] = {2,4,8,9,11,12,20,30};
    int n = sizeof(arr) / sizeof(arr[0]);

twoPointerApproach(arr,n,23);

}