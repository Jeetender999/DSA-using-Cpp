#include <iostream>

using namespace std;

void intersection(int arr1[], int arr2[], int n1, int n2)
{
    // Naive approach
    int res = 0;
    for (int i = 0; i < n1; i++)
    {
        if (i > 0 && arr1[i] == arr1[i - 1])
            continue;

        for (int j = 0; j < n2; j++)
        {
            if (arr2[j] == arr1[i])
            {
                cout << arr1[i] << " ";
                res++;
                break;
            }
        }
    }

    if (res == 0)
        cout << -1 << endl;
}

void intersectionOfTwoSortedArray(int arr1[], int arr2[], int n1, int n2)
{
    int i = 0, j = 0;

    while (i < n1 && j < n2)
    {
        if (i > 0 && arr1[i] == arr1[i - 1])
        {
            i++;
            continue;
        }
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }
}

int main()
{
    int arr1[] = {1, 3, 3, 4, 5, 6, 6, 7, 8, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {2, 3, 8, 9, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    intersectionOfTwoSortedArray(arr1, arr2, n1, n2);
}