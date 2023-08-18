#include <iostream>

using namespace std;

int peakElement(int arr[], int n)
{

    // Naive Approach
    if (arr[0] > arr[1])
        cout << arr[0] << " ";

    for (int i = 0; i < n - 1; i++)
    {

        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            cout << arr[i] << " ";
    }

    if (arr[n - 1] > arr[n - 2])
        cout << arr[n - 1] << " ";
}

int getPeakElement(int arr[], int n)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if ((mid == 0 || arr[mid] > arr[mid + 1]) && (mid == n - 1 || arr[mid] > arr[mid - 1]))
            return arr[mid];

        if ((mid > 0) && arr[mid] <= arr[mid - 1])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int main()
{
    int arr[] = {5, 20, 40, 30, 20, 50, 60};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << getPeakElement(arr, n) << endl;
}