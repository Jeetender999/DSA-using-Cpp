#include <iostream>

#include <algorithm>

using namespace std;

int kthSmallest(int arr[],int n,int k)
{
    sort(arr,arr+n);

    return arr[k-1];
}

int main()
{
    int arr[] = {33,2,5,21,6,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << kthSmallest(arr,n,3);


}