#include <iostream>
using namespace std;

void naivePartition(int arr[],int low,int high,int p)
{
    int* temp = new int[high-low+1];

    int index =0;

    

    for(int i=low;i<=high;i++)
    {
            if(arr[i] < arr[p])
            {
                temp[index] = arr[i];
                 
                 index++;
                
            }
    }
 

     for(int i=low;i<=high;i++)
    {
            if(arr[i] == arr[p])
            {
                temp[index] = arr[i];
                 
                 index++;
                
            }
    }

    for(int i=low;i<=high;i++)
    {
            if(arr[i] > arr[p])
            {
                temp[index] = arr[i];
                
            index++;
            
               
            }
    }

   

     for(int i=low;i<=high;i++)
    {
          arr[i] = temp[i-low];
    }

 cout << endl;
}
int main()
{
    int arr[] = {5,10,1,3,12,6};
    int n= sizeof(arr)/sizeof(arr[0]);

    for(auto x : arr)
    {
        cout <<  x << " ";
    }

  cout << endl;
    naivePartition(arr,0,n-1,1);

     for(auto x : arr)
    {
        cout <<  x << " ";
    }


}