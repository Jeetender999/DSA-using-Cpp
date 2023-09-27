#include <iostream>
#include <unordered_set>

using namespace std;

void pairSumNaive(int arr[], int n, int sum)
{
    for(int i=0;i<n;i++)
    {
          for(int j=i+1;j<n;j++)
          {
            if(arr[i] + arr[j] == sum)
            {
                cout << "Yes" << endl;
                return;
            }
          }
    }

    cout << "No" << endl;
}

bool pairSum(int arr[], int n, int sum)
{
    unordered_set<int> s;

    for(int i=0; i<n;i++)
    {
        if(s.find(sum-arr[i]) != s.end())
        {
            // cout << "YES" << endl;
            return true;
        }

        s.insert(arr[i]);
    }

    // cout << "NO" << endl;
    return false;
}

int main()
{
 int arr[] = {11,5,6};
 int size = sizeof(arr)/sizeof(arr[0]);

  cout << pairSum(arr,size,10);



}
   


