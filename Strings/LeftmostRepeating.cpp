#include <iostream>
#include <algorithm>

using namespace std;

int leftMostNaive(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i + 1; j < str.length(); j++)
        {
            if (str[j] == str[i])
            {

                return i;
            }
        }
    }

    return -1;
}

int leftMost(string str)
{
    int arr[256] = {0};

    for (int i = 0; i < str.length(); i++)
    {
        arr[str[i]]++;
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (arr[str[i]] > 1)
        {
            return i;
        }
    }

    return -1;
}

int leftMostEff1(string str)
{
    int fIndex[256];
    fill(fIndex, fIndex + 256, -1);

    int res = INT_MAX;

    for (int i = 0; i < str.length(); i++)
    {
        if (fIndex[str[i]] == -1)
        {
            fIndex[str[i]] = i;
        }
        else
        {
            res = min(res, fIndex[str[i]]);
        }
    }

    return res;
}

int leftMostEff2(string str)
{
    bool visited[256];
    fill(visited, visited + 256, false);
    int res = -1;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (visited[str[i]] == false)
            visited[str[i]] = true;
        else
        {
            res = i;
        }
    }

    return res;
}

int main()
{
    string str = "abccddd";

    cout << leftMostNaive(str) << endl;
    cout << leftMost(str) << endl;

    cout << leftMostEff1(str) << endl;
    cout << leftMostEff2(str) << endl;
}