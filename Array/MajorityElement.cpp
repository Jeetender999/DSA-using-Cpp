#include <iostream>

using namespace std;

int majorityElement(int arr[], int n)
{

    // Naive Approach
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }

        if (count > n / 2)
        {
            cout << "Element " << arr[i] << " at index " << i << endl;
            return i;
        }
    }

    return -1;
}

int majority(int arr[], int n)
{
    int res = 0;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[res])
            count++;
        else
            count--;

        if (count == 0)
        {
            res = i;
            count = 1;
        }
    }

    count = 0;
    for (int i = 0; i < n; i++)
    {

        if (arr[i] == arr[res])
            count++;
    }

    if (count > n / 2)
        return arr[res];
    else
        return -1;
}

int main()
{
    int arr[] = {1, 3, 2, 1, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int res = majority(arr, n);
    cout << endl
         << res;
}