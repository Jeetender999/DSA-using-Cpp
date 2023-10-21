#include <iostream>
#include <stack>

using namespace std;


bool isMatching(char a, char b)
{
   if((a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']'))
    return true;
   else
    return false;
}

bool isBalanced(string str)
{
     stack<int> s;

     for(int i=0;i<str.length();i++)
     {
       if(str[i] == '{' || str[i] == '(' || str[i] == '[')
         s.push(str[i]);

       else
       {
        if(s.empty() == true)
         return false;

        else if(isMatching(s.top(),str[i]) == false)
         return false;
        else
          s.pop();  
       }  
     }

     if(s.empty() == true) return true;
     else return false;

}

int main()
{
   
    string str = "{()]}";
    cout << isBalanced(str) << endl;

    
    
}