#include <iostream>
#include <algorithm>

using namespace std;

bool isPalNaive(string str)
{
    string rev = str;
    reverse(rev.begin(),rev.end());
    if(rev == str)
    cout << "Yes" << endl;
    else
    cout << "No" << endl;


    return 0;
}

bool isPal(string str)
{
    int i =0, j= str.length() - 1;

    while(i<j)
    {
        if(str[i] != str[j])
         {
            cout << "Not palindrome" << endl;
            return 0;
         }
         i++;
         j--;
    }

    cout << "Palindrome" << endl;
    return 1;
}

int main()
{
    string h = "ABcCBA";
    isPal(h);
}