#include <iostream>
#include <vector>

using namespace std;

bool areDistinct(string str, int i, int j)
{
   vector<bool> visited(256);

   for(int k=i;k<=j;k++)
   {
     if(visited[str[k]] == true)
       return false;
    
    visited[str[i]] = true;
   }

   return true;
}

int longestSubstring(string& str)
{
    int res = 0;
    for(int i=0;i<str.length();i++)
    {

        for(int j=0;j<str.length();j++)
        {
           
           if(areDistinct(str,i,j))
             res = max(res, j-i+1);
           
        }

    }

    return res;
}


int longestDistinct(string& str)
{
  int n = str.length();
  int res = 0;

  for(int i=0;i<n;i++)
  {
    vector<bool> visited(256);

    for(int j=i;j<n;j++)
    {
      if(visited[str[j]] == true)
      {
        break;
      }
      else 
      {
        res = max(res, j-i+1);
        visited[str[j]] = true;
      }
    }
  }

  return res;
}

int main()
{
    string str = "abcd";

    cout << longestSubstring(str) << endl;
    cout << longestDistinct(str) << endl;
}