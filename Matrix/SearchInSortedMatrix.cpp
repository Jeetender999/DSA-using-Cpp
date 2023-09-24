#include <iostream>

using namespace std;

const int R = 3;
const int C = 3;


void searchMatrix(int arr[R][C], int ele)
{
    int i=0, j=C-1;

    while(i<R && j >= 0)
    {
       if(arr[i][j] == ele)
        {
            cout << "Element found at " << i << " " << j << " postion " << endl;
            return;
        }

       else if(arr[i][j] < ele)
       {
        i++;
       } 
       else{
        j--;
       }
    }
 

  cout << "Not found" << endl;

 

}

int main()
{

     int arr[R][C] = {{1, 2, 3}, 
                    {4, 5, 6}, 
                    {7, 8, 9}};


   searchMatrix(arr, 19);
   
}