#include <iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int ele)
{
    if (start > end)
        return -1;

    int mid = (start + end) / 2;

    if (arr[mid] == ele)
        return mid;

    else if (arr[mid] < ele)
    {
        start = mid + 1;
        binarySearch(arr, start, end, ele);
    }

    else if (arr[mid] > ele)
    {
        end = mid - 1;
        binarySearch(arr, start, end, ele);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int arr2[] = {1, 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << binarySearch(arr2, 0, n - 1, 0);
}