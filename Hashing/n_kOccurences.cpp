#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

void nkNaive(int arr[], int n, int k)
{
    sort(arr, arr + n);

    int i = 1;
    int count = 1;
    while (i < n)
    {

        while (i < n && arr[i] == arr[i - 1])
        {
            count++;
            i++;
        }

        if (count > n / k)
            cout << arr[i - 1] << " ";

        count = 1;
        i++;
    }
}




void nkOccurence(int arr[], int n, int k)
{
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }

    for (auto x : m)
    {
        if (x.second > n / k)
            cout << x.first << " ";
    }
}

int main()
{
    int arr[] = {30, 10, 20, 20, 10, 20, 30, 30};
    int size = sizeof(arr) / sizeof(arr[0]);

    nkOccurence(arr, size, 4);
    cout << endl;
    nkNaive(arr, size, 4);
}