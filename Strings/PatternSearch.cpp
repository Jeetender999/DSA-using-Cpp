#include <iostream>

using namespace std;

void patternSearchNaive(string &str, string &ptrn, int m, int n)
{

    for (int i = 0; i <= m - n; i++)
    {

        int j;
        for (j = 0; j < n; j++)
        {
            if (str[i + j] != ptrn[j])
            {

                break;
            }
        }

        if (j == n)
            cout << i << " ";
    }

}

void patternSearchNaiveImproved(string& txt, string& ptr)  // If all distinct elements in Pattern
{
    int m = txt.length();
    int n= ptr.length();

    for(int i=0;i <=m-n;)
    {
        int j;

        for(j=0;j<n;j++)
        {
            if(txt[i+j]!= ptr[j])
            break;
        }

        if(j==n)
        cout << i << " ";

        if(j==0)
        i++;
        else 
        i = i+j;

     
    }
}

int main()
{
    string str = "ABCEABEFABCD";
    string ptrn = "ABCD";
    patternSearchNaive(str, ptrn, str.length(), ptrn.length());
    cout << endl;
     patternSearchNaiveImproved(str, ptrn);
}