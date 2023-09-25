#include <iostream>
#include <unordered_set>

using namespace std;

int countDistinctNaive(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        bool flag = false;

        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
                flag = true;
        }

        if (flag == false)
        { 
            res++;
        }
    }

    return res;
}

int countDistinct(int arr[], int n)
{
  unordered_set<int> s;

  for(int i=0;i<n;i++)
  {
    s.insert(arr[i]);
  }

  return s.size();
}

int main()
{
    int arr[] = {1,1,11,111,34};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << countDistinctNaive(arr,size) << endl;

    // cout << countDistinct(arr,size) << endl;
}