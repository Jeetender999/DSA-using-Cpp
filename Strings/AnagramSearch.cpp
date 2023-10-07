#include <iostream>

using namespace std;


bool areAnagram(string& pat, string& txt, int i) //Some issue with this naive solution
{
    int COUNT[256]  = {0};
    for(int j=0;j< txt.length(); j++)
    {
        COUNT[pat[i]]++;
        COUNT[txt[i+j]]--;
    }

    for(int j=0;j<256;j++)
    {
        if(COUNT[j] != 0)
         return false;
    }

    return true;
}

bool isPresentNaive(string &txt, string &pat)
{
    int n = txt.length();
    int m = txt.length();

    for(int i=0;i<n-m;i++)
    {
        if(areAnagram(pat,txt,i))
       {
        cout << "Naive YES" << endl;
         return true;
       }
    }

   cout << "Naive NO" << endl;
    return false;
}



bool areSame(int CT[], int CP[])
{
    for(int i=0;i<256;i++)
    {
        if(CT[i] != CP[i])
        return false;
    }

    return true;
}
bool isPresent(string txt, string pat)
{
    int CT[256] = {0}, CP[256]={0};

    for(int i=0;i<pat.length();i++)
    {
        CT[txt[i]]++;
        CP[pat[i]]++;
    }

    for(int i=pat.length();i<txt.length();i++)
    {
        if(areSame(CT,CP))
         {
            cout << "Yes" << endl;
            return true;
         }

        CT[txt[i]]++;
        CT[txt[i-pat.length()]]--; 
    }

    cout << "No" << endl;
    return false;
}



int main()
{
 string txt  = "geeksforgeeks";
 string pat = "frok";


 cout << isPresent(txt,pat) << endl;
}