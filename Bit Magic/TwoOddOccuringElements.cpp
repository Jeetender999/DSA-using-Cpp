#include <iostream>

using namespace std;

void twoOddOccuringElements(int arr[], int n)
{

    int XOR = 0;
     int res1=0;
    int res2=0;

    for(int i=0;i<n;i++){
        XOR = XOR^arr[i];
    }

    int sn = XOR &~(XOR-1);

    for(int i=0;i<n;i++){

        if((arr[i] & sn) !=0){
            res1= res1^arr[i];
        }else{
            res2=res2^arr[i];
        }
    }

    cout << "The two elements are " << endl;
    cout << res1 << " and " << res2 << endl;
}
int main(){

  int arr[] = {1,1,2,2,2,3,3,4,4,5,5,5,6,6,7,7};
  int n = sizeof(arr)/sizeof(arr[0]);

  twoOddOccuringElements(arr,n);
}