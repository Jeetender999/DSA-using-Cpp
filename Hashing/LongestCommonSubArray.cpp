#include <iostream>
#include <unordered_map>

using namespace std;

int commonMaxNaive(int a[], int b[], int m, int n)
{
    int res = 0;
    for(int i=0;i<m;i++)
    {
        int sum1=0, sum2=0;
        for(int j=i;j<n;j++)
        {
            sum1 += a[j];
            sum2 += b[j];

            if(sum1 == sum2)
              res = max(res, j-i+1);
        }
    }

    return res;
}

int maxCommon(int a[], int b[], int size)
{

    int res = 0;
    int pre_sum = 0;
    unordered_map<int,int> m;

    int* temp = new int[size];

    for(int i=0;i<size;i++)
      temp[i] = a[i] - b[i];

    for(int i=0;i<size;i++)
    {
        pre_sum += temp[i];

        if(pre_sum == 0)
         res = i+1;

        if(m.find(pre_sum) == m.end())
        {
            m.insert({pre_sum, i});
        } 

        if(m.find(pre_sum) != m.end())
        {
            res = max(res, i - m[pre_sum]);
        }
        
    }

    return res;
}

int main()
{
    int a[] = {0,1,0,0,0,0};
    int b[] = {1,0,1,0,0,1};

  
    int m = sizeof(a)/sizeof(a[0]);
     int n = sizeof(b)/sizeof(b[0]);
    
    cout << commonMaxNaive(a,b,m,n) << endl;
    cout << maxCommon(a,b,m);
}