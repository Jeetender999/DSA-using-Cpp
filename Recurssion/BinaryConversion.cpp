#include <iostream>

using namespace std;

void decimalToBinary(int num){

 if(num == 0)
 return;

 decimalToBinary(num/2); cout << num%2 << "";
}
int main(){

  decimalToBinary(7);
}