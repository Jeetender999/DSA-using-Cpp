#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Union(int a[], int b[], int m, int n)
{
    int *arr = new int[m + n];

    for (int i = 0; i < m; i++)
    {
        arr[i] = a[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i + m] = b[i];
    }

    int size = m + n;

    sort(arr, arr + size);

    for (int i = 0; i < size; i++)
    {
        if (i == 0 || arr[i] != arr[i - 1])
            cout << arr[i] << " ";
    }
}

void unionOfTwoSortedArray(int a[], int b[], int m, int n)
{
    int i = 0, j = 0;

    while (i < m && j < n)
    {

        if (i > 0 && a[i] == a[i - 1])
        {
            i++;
            continue;
        }
        if (a[i] < b[j])
        {
            cout << a[i] << " ";
            i++;
        }
        else if (b[j] < a[i])
        {
            cout << b[j] << " ";
            j++;
        }
        else if (a[i] = b[j])
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }

    while (i < m)
    {
        if (a[i] != a[i - 1] && i > 0)
        {
            cout << a[i] << " ";
            i++;
        }
    }

    while (j < n)
    {
        if (b[j] != b[j - 1] && j > 0)
        {
            cout << b[j] << " ";
            j++;
        }
    }
}

int main()
{
    int a[] = {1, 3, 3, 4, 5, 6, 6, 7, 8, 9};
    int m = sizeof(a) / sizeof(a[0]);
    int b[] = {2, 3, 8, 9, 10};
    int n = sizeof(b) / sizeof(b[0]);

    unionOfTwoSortedArray(a, b, m, n);
}