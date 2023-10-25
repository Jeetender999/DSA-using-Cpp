#include <iostream>

using namespace std;

int getMaxArea(int arr[], int n)
{

     int maxRes = 0;
    for(int i=0;i<n;i++)
    {
        int res = arr[i];
         int j=0;
        for( j=i-1;j>=0;j--)
        {
           if(arr[j] >= arr[i])
           res = res + arr[i];
           else
            break;
        }

       
        for(j=i+1;j<n;j++)
        {
            if(arr[j] >= arr[i])
            res = res + arr[i];
            else
             break;
             
        }

        cout << res << " ";

        maxRes = max(res, maxRes);
        
    }


    cout << endl<<"Max result " << maxRes << endl;
}

int main()
{
    int arr[] = {6,2,5,4,1,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);

    getMaxArea(arr,size);


}