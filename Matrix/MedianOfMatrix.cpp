#include <iostream>

using namespace std;

const int R = 3;
const int C =3;

int medianOfMatrix(int arr[3][3])
{
    int min= arr[0][0], max=arr[0][C-1];

    for(int i=1;i<R;i++)
    {
        if(arr[i][0] < min)
        {
            min = arr[i][0];
        }


        if(arr[i][C-1] > max)
        {
            max = arr[i][C-1];
        }
    }

    int medPos = (R*C+1)/2;

    while(min < max)
    {
     int mid = (min+max)/2;
     int midPos = 0;


     for(int i=0;i<R;i++)
     {
      midPos += UPPER_BOUND(arr[i],arr[i]+C,mid)-m[i];
     }


     if(midPos < medPos)
     {
        min = mid+1;
     }
     else{
        max = mid;
     }
    }

    return min;
}

int main()
{
    int arr[3][3] = {{3,6,9},{2,4,8},{1,5,7}};


}