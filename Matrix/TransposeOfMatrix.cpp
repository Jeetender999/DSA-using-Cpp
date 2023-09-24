#include <iostream>
#include <algorithm>

using namespace std;

const int R = 3;
const int C = 3;


void transposeArray(int arr[R][C])
{

 
    for (int i = 0; i < R; i++)
    {
        for (int j = i+1; j < C; j++)
        {
            swap(arr[i][j],arr[j][i]);
        }

    }
}

void printArray(int arr[R][C])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }
}

int main()
{
    int arr[R][C] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
     
    transposeArray(arr);
    printArray(arr);
}