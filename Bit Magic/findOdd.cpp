#include <iostream>
#include <vector>

using namespace std;

int findOdd(int arr[], int n){
    int res = 0;
 for(int i=0;i<n;i++)
   {
     res  = res ^ arr[i];
   }

   return res;
}

int main(){

 int arr[] = {8,8,8,8,9,9,10,10,11,11,11,11,9};
 int size = sizeof(arr)/sizeof(arr[0]);

 
  int res =  findOdd(arr,size);

  cout << res << endl;

   
 }

 

 
