#include <iostream>
#include <algorithm>

using namespace std;

void reverseStr(char str[], int n)
{
    int start = 0;
   for(int end=0;end<n;end++)
   {
    if(str[end] == ' ')
    {
        reverse(str+start,str+end);
        start = end+1;
    }
   }

   reverse(str+start,str+n);
   reverse(str,str+n);
}

int main()
{
    char str[] = "abc";
    int size = sizeof(str)/sizeof(str[0]) -1;
    cout << size << endl;
    cout << str << endl;
    reverseStr(str,size);
    cout << str << endl;
    
}