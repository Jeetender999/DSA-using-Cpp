#include <iostream>
#include <algorithm>

using namespace std;

bool subSequence(string& str1, string& str2, int m, int n)
{

    if(m < n)
     return 0;


    int i= 0;
    int j = 0;

    while(i<m && j <n)
    {
        if(str1[i] == str2[j])
        {
            i++;
            j++;

        }
        else 
        {
            i++;
        }
    }

    return(j == n);
}

bool recuriveSubSeq(string& s1, string& s2, int m, int n, int i, int j)
{

    if(i<m && j<n)
    {
        if(s1[i] == s2[j])
        {
            i++;
            j++;
           return recuriveSubSeq(s1,s2,m,n,i,j);
        }
        else{
            i++;
            return recuriveSubSeq(s1,s2,m,n,i,j);
        }
    }


    if(j == n)
    {
        cout << "SUBSEQ" << endl;
        return 1;
    }
    else{
        cout << "NOT SUBSEQ" << endl;
        return 0;
    }

}

bool recuriveSubSeq2(string& s1, string& s2, int m, int n)
{
    if(n == 0)
    {
        cout << "Yes Sub Sequence" << endl;
        return 1;
    }

    if(m == 0)
    {
        cout << "Not a Sub Sequence" << endl;
        return 0;
    }


    if(s1[m-1] == s2[n-1])
    {
        return recuriveSubSeq2(s1,s2,m-1,n-1);
    }
    else
    {
        return recuriveSubSeq2(s1,s2,m-1,n);
    }
}

int main()

{
    string str1 = "ABC";
    int m = str1.length();

    string str2 = "AC";
    int n = str2.length();
   

   cout << subSequence(str1,str2,m,n) << endl;

   recuriveSubSeq(str1,str2,m,n,0,0);
   recuriveSubSeq2(str1,str2,m,n);

}