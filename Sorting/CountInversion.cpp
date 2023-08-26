#include <iostream>

using namespace std;

int countInversion(int arr[], int n)
{
  int count = 0;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (arr[i] > arr[j])
        count++;
    }
  }

  return count++;
}

int countandMerge(int arr[], int l, int mid, int r)
{
  int n1 = mid - l + 1;
  int n2 = r - mid;

  int *left = new int[n1];
  int *right = new int[n2];

  for (int i = 0; i < n1; i++)
  {
    left[i] = arr[l + i];
  }

  for (int j = 0; j < n2; j++)
  {
    right[j] = arr[mid + 1 + j];
  }

  int i = 0, j = 0, k = l, res = 0;
  while (i < n1 && j < n2)
  {
    if (left[i] <= right[j])
    {
      arr[k] = left[i];
      i++;
    }
    else
    {
      arr[k] = right[j];
      j++;
      res = res + (n1 - i);
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = left[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = right[j];
    j++;
    k++;
  }

  return res;
}

int countInversionMerge(int arr[],int l,int r)
{
  int res = 0;

  if(l < r)
  {
    int mid = l + (r-l)/2;
    res += countInversionMerge(arr,l,mid);
    res += countInversionMerge(arr,mid+1,r);
    res += countandMerge(arr,l,mid,r);
  }

  return res;
}

int main()
{
  int arr1[] = {2,4,1,3,5};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);

  cout << countInversionMerge(arr1,0,n1-1);

  return 0;
}