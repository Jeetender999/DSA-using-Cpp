#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str, int start, int end)
{
    if (start > end)
        return true;

    return (str[start] == str[end]) && isPalindrome(str, start + 1, end - 1);
}

int main()
{

    string str = "madam";
    int len = str.length();

    if (isPalindrome(str, 0, len - 1))
        cout << "Palindrome";
    else
        cout << "Not a palindrome";
}