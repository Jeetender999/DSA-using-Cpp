#include <iostream>
#include <unordered_set>

using namespace std;

void zeroSumNaive(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        int sum =0;
        for(int j=i;j<n;j++)
        {
            sum += arr[j];
            if(sum == 0)
            {
                cout << "YES";
                return;
            }
        }
    }

 cout << "NO";
}

bool zeroSum(int arr[], int n)
{
    unordered_set<int> s;
    
    int pre_sum =0;
    for(int i=0;i<n;i++)
    {
        pre_sum += arr[i];

       if(s.find(pre_sum) != s.end())
       {
         cout << "YES" << endl;
         return true;
       }

       if(pre_sum == 0)
         {
           cout << "YES" << endl;
         return true;
         }


       s.insert(pre_sum);
      
    }

    cout << "NO" << endl;
    return false;
}

int main()
{
    int arr[] = {1,2,3,-1,-4};
    int size = sizeof(arr)/sizeof(arr[0]);
     zeroSum(arr,size);
}