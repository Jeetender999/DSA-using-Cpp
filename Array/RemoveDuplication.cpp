#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Only for sorted array
int removeDuplication(int arr[], int n)
{

    vector<int> v;
    v.push_back(arr[0]);
    int res = v.size();

    for (int i = 1; i < n; i++)
    {

        if ((v.at(res - 1) != arr[i]))
        {
            v.push_back(arr[i]);
            res++;
        }
    }

    for (auto x : v)
    {
        cout << x << " ";
    }

    return v.size();
}


int removeDuplication2(int arr[], int n)
{

    int res = 1;

    for (int i = 1; i < n; i++)
    {

        if (arr[i] != arr[res-1])
        {
            arr[res] = arr[i];
            res++;
        }
    }

    return res;
}
int main()
{

    int arr[] = {3, 3, 10, 1, 2, 4, 4, 5, 5, 5, 10};

    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);

    int size = removeDuplication2(arr, n);

    cout << "Size " << size << endl;

   
}