#include <iostream>

using namespace std;

// Power Of 2

bool isPowOf2(int num){

   //Naive Solution

  if(num == 0) return false;
  while(num > 1){

    if(num % 2 !=0)
     return false;

    num = num/2; 
  }

  return true;
}

bool isPowerOf2(int num){

  //OPtimized Solution

  if(num == 0) return false;

  if((num & num-1)== 0) return true;
  else return false;
}


int main(){


  if(isPowerOf2(2050)){
    cout << "Power of 2" << endl;
  }
  else{
    cout << "Not power of 2" << endl;
  }
}