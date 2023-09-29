#include <iostream>
#include <unordered_set>

using namespace std;

void givenSumNaive(int arr[], int n, int k)
{
    for(int i=0;i<n;i++)
    {
        int sum = 0;
        for(int j=i;j<n;j++)
        {
          sum += arr[j];

          if(sum == k)
          {
            cout << "Yes";
            return;
          }
        }
    }

    cout << "No" << endl;
}

bool givenSum(int arr[], int n, int k)
{
    int pre_sum = 0;
    unordered_set<int> s;

    for(int i=0;i<n;i++)
    {
         pre_sum += arr[i];

         if(pre_sum == k)
         {
            cout << "yes" << endl;
            return true;
         }

         if(s.find(pre_sum-k) != s.end())
         {
            cout << "Yes" << endl;
            return true;
         }
         s.insert(pre_sum);


    }
    cout << "False" << endl;
    return false;
}
int main()
{
     int arr[] = {5,8,6,13,3,-1};
    int size = sizeof(arr)/sizeof(arr[0]);

    givenSum(arr,size,-1);
}