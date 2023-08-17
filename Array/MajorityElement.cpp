#include <iostream>

using namespace std;

int majorityElement(int arr[],int n){
    
    

     for(int i=0;i<n;i++){
        int count = 1;
        for(int j=i+1;j<n;j++){
            if(arr[i] == arr[j])
             count++;
        }

        if(count > n/2)
         {cout << "Element " << arr[i] << " at index " << i << endl;
            return i;}
     }

     return -1;


}

int main(){
    int arr[] = {1,3,3,1,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    int res = majorityElement(arr,n);
    cout << endl << res;

       

}