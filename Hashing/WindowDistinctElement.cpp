#include <iostream>
#include <unordered_set>

using namespace std;

int windowDistinctElement(int arr[], int n, int k)
{

   

   for(int i=0;i<= n-k;i++)
   {
    int count = 0;
     for(int j=0;j<k;j++)
     {
        int flag = false;

        for(int p =0; p<j;p++)
        {
            if(arr[j+i] == arr[p+i])
             {
                flag = true;
                break;
             }
        }

        if(flag == false)
         count++;
     }

     cout << count << " ";
   } 

   return 0;
//     unordered_set<int> s;
  
//   for(int i=0;i<n-k+1;i++)
//   {
//     int count = 0;
//     for(int j=i;j<i+k;j++)
//     {
//       s.insert(arr[j]);
//     }

//     cout << s.size() << " ";

//     s.clear();
   
//   }
}


int main()
{
    int arr[] = {10,10,5,3,20,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    windowDistinctElement(arr,size,4);

}