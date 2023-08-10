#include <iostream>

using namespace std;

int countSetBits(int num){
// Naive Solution
  int count = 0;
   while(num>0){
    if(num & 1 ){
        count++;
    }
    num = num>>1;
   }

   return count;
}

int countSetBits2(int num){

  // Brian Kerningam's Algorithm
    int count = 0;

    while(num>0){

        num = (num & (num-1));
        count++;
    }

    return count++;
}
int main(){

 
 cout << countSetBits(8) << endl;
 cout << countSetBits2(8) << endl;
}