#include <iostream>
#include <unordered_map>

using namespace std;

int longest01SubArrayNaive(int arr[], int n)
{
    int res = 0;
    for(int i=0;i<n;i++)
    {
        int c0 =0 ,c1 =0;

        for(int j=i;j<n;j++)
        {
            if(arr[j] == 0)
            c0++;
            else
            c1++;

            if(c0 == c1)
            {
                res = max(res,j-i+1);
            }

        
        }
    }

    return res;
}


int longest01SubArray(int arr[], int n )
{
    

    for(int i=0;i<n;i++)
    {
        if(arr[i] == 0)
         arr[i] = -1;
    }

    int pre_sum = 0;
    int res = 0;
    unordered_map<int,int> m;

    for(int i=0;i<n;i++)
    {
        pre_sum += arr[i];

        if(pre_sum == 0)
          res = i+1;

        if(m.find(pre_sum) == m.end())
        {
           m.insert({pre_sum, i});
        }

        if(m.find(pre_sum ) != m.end())
        {
            res = max(res, i- m[pre_sum]);
        }

    }

    return res;
}

int main()
{
 int arr[] = {1,0,1,1,1,0,0};
 int size = sizeof(arr)/sizeof(arr[0]);
 cout << longest01SubArrayNaive(arr,size) << endl;
 cout << longest01SubArray(arr,size) << endl;



}