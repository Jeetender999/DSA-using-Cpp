#include <iostream>
#include <unordered_set>

using namespace std;

int unionNaive(int a[], int b[], int m, int n)
{
    int* c = new int[m+n];

    for(int i=0;i<m;i++)
    {
        c[i] = a[i];
    }

    for(int j=0;j<n;j++)
    {
        c[j+m] = b[j];
    }

    int res = 0;
    for(int i=0;i<m+n;i++)
    {
        int flag = false;
        for(int j=0;j<i;j++)
        {
            if(c[i] == c[j])
            {
                flag = true;
            }
        }

        if(flag == true)
        continue;

        res++;
    }

    return res;
}
 
int Union(int arr1[], int arr2[], int n1, int n2)
{
    unordered_set<int> s;

    for(int i=0;i<n1;i++)
     s.insert(arr1[i]);

      for(int j=0;j<n2;j++)
     s.insert(arr2[j]);

     return s.size();
}
int main()
{
    int arr1[] = {1,2,3,4,5};
    int arr2[] = {3,4,5,6,7,1,22,8};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
     int size2 = sizeof(arr2) / sizeof(arr2[0]);

   cout << unionNaive(arr1,arr2,size1, size2) << endl;

   cout << Union(arr1,arr2,size1,size2) << endl;
     

    
}