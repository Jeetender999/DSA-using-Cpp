#include <iostream>
#include <math.h>

using namespace std;

void powerSet(string str){
    int n = str.length();
    int powSize = pow(2,n);
     
    for(int counter=0;counter<powSize;counter++){

        for(int i=0;i<n;i++){

            if((counter & (1<<i)) != 0){
                cout << str[i];
            }
        }

        cout << '\n';
    }
}

int main(){
    string str = "abc";

    powerSet(str);

}