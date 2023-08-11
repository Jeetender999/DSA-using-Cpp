#include <iostream>

using namespace std;

int factorial(int num){
    if(num==0 || num==1)
    return 1;

    return num * factorial(num-1);

}

int fibonacci(int num){
    if(num == 0)
     return 0;

    if(num == 1)
    return 1;

    int fib = fibonacci(num-1) + fibonacci(num-2); 
    return fib;
}
int main(){
 
  int fac = fibonacci(5);
  cout << fac << endl;
}