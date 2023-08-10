#include <iostream>

using namespace std;


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


  int setBits = countSetBits2(1024);

  if(setBits == 1) {
    cout << "Power of 2" ;
  }else cout << "Not power of 2";
}