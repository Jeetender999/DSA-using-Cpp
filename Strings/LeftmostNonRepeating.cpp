#include <iostream>

using namespace std;

int leftmostNonNaive(string& str)
{
    for(int i=0; i < str.length(); i++)
    {
        bool flag = false;
        for(int j=0;j < str.length();j++)
           {
            if(i != j && str[j] == str[i])
             {
               flag = true;
               break;
             }
           }

        if(flag == false)
          return i;     
         
    }

    return -1;
}

int leftMost(string& str)
{
    int count[256] = {0};

    for(int i=0;i<str.length();i++)
    {
        count[str[i]]++;
    }

    for(int i=0;i<str.length();i++)
    {
        if(count[str[i]] == 1)
         return i;
    }

    return -1;
}

int leftmostNonEff(string& str)
{
   
   int count[256];
   fill(count,count+256,-1);

   for(int i=0;i<str.length();i++)
   {
    if(count[str[i]] == -1)
    {
        count[str[i]] = i;
    }
    else 
     count[str[i]] = -2;
   }

  int res  = INT_MAX;
  for(int i=0;i<256;i++)
  {
     if(count[i] >= 0)
      res = min(res, count[i]);
  }

  return (res == INT_MAX) ? -1 : res;
   
}

int main()
{
   string str = "abbcbda";
   cout << leftmostNonNaive(str) << endl;
    cout << leftMost(str) << endl;
    cout << leftmostNonEff(str) << endl;
}