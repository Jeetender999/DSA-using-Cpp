#include <iostream>

using namespace std;

int sqrtBinary(int num){
    int low=0, high = num;
    int ans = -1;
    while(low<=high){
        int mid = (low+high)/2;
        
        int sq = mid*mid;

        if(sq == num)
          return mid;
        else if(sq > num )
          high = mid-1;
        else {
           low = mid+1;
           ans = mid;
        }
        
    }

    return ans;
}

int main(){
   cout << sqrtBinary(15) << endl;
}