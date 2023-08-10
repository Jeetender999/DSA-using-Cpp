#include <iostream>

using namespace std;

bool kthBit(int num, int k){

    if(num & 1<<(k-1)){
        cout << "Yes " << k <<"th bit is a Set bit" << endl;
    }
    else{
        cout << "No, not a set bit" << endl;
    }

}



int main(){
   
  kthBit(5,4);
}