#include<iostream>

using namespace std;

void printNumbersReverse(int num){

   if(num == 0)
     return;

    cout << num << " ";
    printNumbersReverse(num-1);
}

void printNumbers(int num){

   if(num == 0)
     return;

    
    printNumbers(num-1);
    cout << num << " ";
}

int main(){

    printNumbers(10);

}