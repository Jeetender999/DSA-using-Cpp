#include <iostream>
#include <algorithm>

using namespace std;


//INCOMPLETE

int longestConsecutive(int arr[],int n)
{
    // Using sorting nlogn
    sort(arr,arr+n);
    int curr=1 ,res =1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]-arr[i-1] == 1)
          curr++;
        else
        {
            res = max(res,curr);
            curr = 1;
        }
    }

    res = max(res,curr);

    return res;
}

int main()
{
    int arr[] = {1,9,3,4,2,20,6,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << longestConsecutive(arr,size) << endl;
}