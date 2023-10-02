#include <iostream>
#include <algorithm>

using namespace std;

bool isAnagramWorst(string& s1, string& s2, int m,int n)
{
    for(int i=0;i<m;i++)
    {
        int c1 = 0, c2 =0;

        for(int j=0;j<n;j++)
        {
           if(s2[j] == s1[i] )
           {
             c2++;
           }

           if(s1[i] == s1[j])
           c1++;
        }

        if(c1 != c2)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 1;
}

bool areAnagramNaive(string& s1, string& s2, int m, int n)
{
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());

    return(s1 == s2);
}


bool areAnagram(string& s1, string& s2, int m, int n)
{
     if(m != n)
     return false;

     int freq[256] = {0};

     for(int i=0;i<m;i++)
     {
        freq[s1[i]]++;
        freq[s2[i]]--;
     }

     for(int i=0;i<256;i++)
     {
        if(freq[i] != 0)
        return false;
     }

     return true;
}


int main()
{
    string s1 = "hello";
    int m = s1.length();

    string s2 = "ollei";
    int n = s2.length();

    isAnagramWorst(s1,s2,m,n);
    cout << areAnagramNaive(s1,s2,m,n) << endl;
    cout << areAnagram(s1,s2,m,n) << endl;


}