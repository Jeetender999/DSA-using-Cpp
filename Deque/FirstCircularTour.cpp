#include <iostream>
#include <deque>

using namespace std;

int firstCircularTour(int petrol[], int dist[], int n)
{
    for(int start=0;start<n;start++)
    {
        int totalPetrol =0;
        int end = start;

        while(true)
        {
          totalPetrol += (petrol[end]-dist[end]);

          if(totalPetrol < 0)
           break;

           end = (end+1)%n;

          if(end == start)
           return start+1;
        }
    }

    return -1;
}

int firstCircularTourEfficient(int petrol[], int dist[], int n)
{
    int curr_petrol =0;
    int prev_petrol=0;
    int start = 0;

    for(int i=0;i<n;i++ )
    {
        curr_petrol += (petrol[i]-dist[i]);

        if(curr_petrol < 0)
        {
            start = i+1;
            prev_petrol = curr_petrol;
            curr_petrol = 0;
        }
    }

    return (curr_petrol+prev_petrol >= 0 ? start+1 : -1 );
}

int main()
{
    int petrol[]={4,8,7,4};
    int dist[]={6,5,3,5};
    int n1 = sizeof(petrol)/sizeof(petrol[0]);
    int n2 = sizeof(dist)/sizeof(dist);

    cout << firstCircularTourEfficient(petrol,dist,n1);
}