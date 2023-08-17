#include <iostream>
#include <algorithm>

using namespace std;

int maxEvenOdd(int arr[], int n)
{
    // Naive Approach
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        int curr = 1;

        for (int j = i + 1; j < n; j++)
        {
            if ((arr[j - 1] % 2 == 0 && arr[j] % 2 != 0) || (arr[j - 1] % 2 != 0 && arr[j] % 2 == 0))
                curr++;
            else
                break;
        }
        res = max(res, curr);
    }

    return res;
}

int maximumEvenOdd(int arr[], int n)
{
    int res = 1;
    int cur = 1;

    for (int i = 1; i < n; i++)
    {

        if ((arr[i] % 2 == 0 && arr[i - 1] % 2 != 0) || (arr[i] % 2 != 0 && arr[i - 1] % 2 == 0))
        {
            cur++;
            res = max(res, cur);
        }
        else
            cur = 1;
    }

    return res;
}

int main()
{
    int arr[] = {5, 10, 20, 6, 3, 8, 5, 6};

    int n = sizeof(arr) / sizeof(arr[0]);
    int res = maxEvenOdd(arr, n);
    cout << endl
         << res << endl;

    int res1 = maximumEvenOdd(arr, n);
    cout << endl
         << res1 << endl;
}