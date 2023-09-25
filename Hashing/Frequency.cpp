#include <iostream>
#include <unordered_map>

using namespace std;

void frequencyNaive(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {

        int flag = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                flag = true;
                break;
            }
        }

        if (flag == true)
            continue;

        int freq = 0;

        for (int j = i; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                freq++;
            }
        }

        cout << "Freq of " << arr[i] << " : " << freq << endl;
    }
}

void frequency(int arr[], int n)
{

    unordered_map<int,int> m;

    for(int i=0;i<n;i++)
    {
         m[arr[i]]++;
    }

    for(auto x : m)
    {
        cout << x.first << " : " << x.second << endl;
    }
}

int main()
{
    int arr[] = {1, 1, 11, 111, 34};
    int size = sizeof(arr) / sizeof(arr[0]);

    frequency(arr, size);
}