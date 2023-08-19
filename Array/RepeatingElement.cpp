#include <iostream>
#include <vector>
using namespace std;


int repeatingElement(int arr[], int n)
{
    vector<bool> v(n,false);
    
    for(int i=0;i<n;i++)
    {
        if(v[arr[i]])
        return arr[i];
        else 
        v[arr[i]] = true;
    }

  return -1;

   
}
int main()
{
    int arr[]={0,0};
    int n = sizeof(arr)/sizeof(arr[0]);
   cout <<  repeatingElement(arr,n);
}