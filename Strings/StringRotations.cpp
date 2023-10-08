#include <iostream>

using namespace std;

int areRotation(string& str1, string& str2)
{
    if(str1.length() != str2.length()) return false;

    return ((str1+str1).find(str2) != string::npos);
}

int main()
{
    string str1 = "hello";
    string str2 = "elloh";

    string str = str1+str2;
    
    if(areRotation(str1,str2))
    cout << "String rotation" << endl;
    else
    cout << "Not a string rotation" << endl;
    
}