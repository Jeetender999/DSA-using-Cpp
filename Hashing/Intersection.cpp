#include <iostream>
#include <unordered_set>

using namespace std;

int intersectionNaive(int a[], int b[], int m, int n)
{
    int res = 0;
    for (int i = 0; i < m; i++)
    {
        bool flag = false;

        for (int j = 0; j < i; j++)
        {
            if (a[i] == a[j])
            {
                flag = true;
                break;
            }
        }

        if (flag == true)
            continue;

        for (int j = 0; j < n; j++)
        {
            if (a[i] == b[j])
            {
                res++;
                break;
            }
        }
    }

    return res;
}

int intersection(int arr1[], int arr2[], int n1, int n2)
{
    unordered_set<int> s;
    int res = 0;
    for (int i = 0; i < n1; i++)
        s.insert(arr1[i]);

    for (int j = 0; j < n2; j++)
    {
        if (s.find(arr2[j]) != s.end())
        {
            res++;
            s.erase(arr2[j]);
        }
    }

    return res;
}
int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {3, 4, 5, 6, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << intersection(arr1, arr2, size1, size2) << endl;
    cout << intersectionNaive(arr1, arr2, size1, size2) << endl;
}