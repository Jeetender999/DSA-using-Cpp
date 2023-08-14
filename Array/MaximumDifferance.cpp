#include <iostream>
#include <algorithm>

using namespace std;

int maxDifferance(int arr[],int n){

  int maxdiff = arr[1]-arr[0];

  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if((arr[j] - arr[i])>maxdiff)
          maxdiff = arr[j]-arr[i];
    }
  }

  return maxdiff;
}

int maxDiff(int arr[],int n){
    int res = arr[1]-arr[0];
    int minEle = arr[0];

    for(int j=1;j<n;j++){
        res = max(res,arr[j]-minEle);
        minEle = min(minEle,arr[j]);
    }

    return res;
}

int main(){
  int arr[] = {7,9,5,6,3,2};
    int n= sizeof(arr)/sizeof(arr[0]);

  int res = maxDiff(arr,n);
  cout << res << endl;


}