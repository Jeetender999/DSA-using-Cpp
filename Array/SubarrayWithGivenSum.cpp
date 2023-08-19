#include <iostream>
#include <vector>
using namespace std;


 vector<int> subarrayWithGivenSum(int arr[],int n, int sum)
 {
    int curr_sum = arr[0];
    int start=0;
    vector<int> res = {};

    for(int end=1;end<=n;end++){
 
       

         while(curr_sum > sum && start < end-1)
         {
            curr_sum -= arr[start];
            start++;
         }

        
         if(curr_sum == sum)
         {
            int startPosition = start+1;
            int endPosition = end;
            res.push_back(startPosition);
            res.push_back(endPosition);
            return res;
         }

         if(end<n)
           curr_sum += arr[end];

    }

    vector<int> r = {-1};
    return r;
    
 }

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int n= sizeof(arr)/sizeof(arr[0]);
    vector<int> res = subarrayWithGivenSum(arr,n,132);

    for(auto x : res)
    cout << x << " ";
}