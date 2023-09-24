#include <iostream>

using namespace std;

const int R = 3;
const int C = 3;

const int N = 3;

void RotateMatrixAntiClockwise(int arr[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
    }


    for(int i=0;i<N;i++)
    {
        int low=0, high = N-1;

        while(low<=high)
        {
            swap(arr[low][i],arr[high][i]);
            low++;
            high--;
        }
    }

}


void printMatrix(int arr[R][C])
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

     int arr[R][C] = {{1, 2, 3}, 
                    {4, 5, 6}, 
                    {7, 8, 9}};

    RotateMatrixAntiClockwise(arr);

    printMatrix(arr);
}