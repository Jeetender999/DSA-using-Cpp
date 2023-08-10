#include<iostream>>

using namespace std;

//Program to find Missing number from given range

int main(){
    int arr[] = {1,3,4,5};

    int start = 1;
    int end = 5;
    int res1=0;
    int res2=0;

    for(int i=0;i<4;i++){
       res1 = res1^arr[i];
    }

   
    for(int i=start; i<=end;i++){
        res2 = res2 ^ i;
    }


    cout << "The missing number is " << (res1^res2 )<<endl;
}