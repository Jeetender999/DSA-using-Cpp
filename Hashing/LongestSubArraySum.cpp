#include <iostream>
#include <unordered_map>

using namespace std;

int longestSumNaive(int arr[], int n, int sum)
{
    int res = 0;
    for(int i=0;i<n;i++)
    {
        int curr_sum = 0;
        int count =0; 
        for(int j=i;j<n;j++)
        {
           curr_sum+= arr[j];
           count++;
           if(curr_sum == sum)
           {
            res = max(count,res);   // or   res = max(j-i+1,res);
           }
        }
    }

    return res;
}

int longestSum(int arr[], int n ,int sum)
{
    int pre_sum = 0;
    int res = 0;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        pre_sum += arr[i];

        if(pre_sum == sum)
          res = i+1;

        if(m.find(pre_sum) == m.end())
        {
           m.insert({pre_sum, i});
        }

        if(m.find(pre_sum - sum) != m.end())
        {
            res = max(res, i- m[pre_sum - sum]);
        }

    }

    return res;
}
int main()
{
 int arr[] = {8,3,1,5,-6,-6,2,2};
 int size = sizeof(arr)/sizeof(arr[0]);

 cout << longestSum(arr,size,4) << endl;
  cout << longestSumNaive(arr,size,4);

}