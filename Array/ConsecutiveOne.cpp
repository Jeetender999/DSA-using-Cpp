#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int consecutiveOne(int arr[],int n){
   
    int count = 0;
   
     int curCount = 0;

    for(int i=0;i<n;i++){
      
        if(arr[i] == 0)
          curCount=0;
        else{
            curCount++;
            count = max(count,curCount);
        }
    }

   
    return count;
}



int consecutiveOnes(int arr[],int n){
  //Naive solution
  int res = 0;
 int currCount = 0;
  for(int i=0;i<n;i++){
   currCount = 0;

    for(int j=i;j<n;j++){
        if(arr[j] == 1) 
        {
            currCount++;
        
        }
        else break;
    }

    res = max(res,currCount);
  }

  return res;
}
int main(){

    int arr[] = {1,0,1,1,0,1,1,1,1};
    int n= sizeof(arr)/sizeof(arr[0]);

    int res = consecutiveOne(arr,n);
    int res2 = consecutiveOnes(arr,n);
   
     cout << endl << res << endl;
     cout << endl << res2 << endl;

}