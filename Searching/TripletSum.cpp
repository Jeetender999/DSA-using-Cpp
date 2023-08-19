#include <iostream>

using namespace std;


int pairSum(int arr[], int left,int right,int k)
{
    

    while(left < right){

        if(arr[left]+arr[right]==k)
          {
            cout << arr[left] << " " << arr[right] << " ";
            return 1;
          }

        if(arr[left]+arr[right] > k)
          right = right -1;

        if(arr[left] + arr[right] < k)
          left = left+1;  
    }

    
    return 0;
}

int tripletSum(int arr[], int n,int sum)
{
   for(int i=0;i<n;i++)
   {
      if(pairSum(arr,i+1,n-1,sum-arr[i]))
     {
         cout << arr[i] << " " << endl;
         return 1;
     }
   }
 
 cout << "Triplet not found" << endl;

}

int main(){
 int arr[] = {2,4,8,9,11,12,20,30};
    int n = sizeof(arr) / sizeof(arr[0]);

   tripletSum(arr,n,100);

}