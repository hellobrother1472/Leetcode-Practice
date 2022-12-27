#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestOddNumber(string num)
    {
        int n = num.length();
        int index = -1;
        string ans = "";
        for (int i = n - 1; i >= 0; i--)
        {
            int ascii = num[i];
            if (ascii % 2 != 0)
            {
                index = i;
                break;
            }
        }
        for (int i = 0; i <= index; i++)
            ans += num[i];
            
        return ans;
    }
};

class Solution
{
public:
    string largestOddNumber(string num)
    {
        int n = num.length();
        for (int i = n - 1; i >= 0; i--)
        {
            int ascii = num[i];
            if (ascii % 2 == 0)
                num.pop_back();
            else
                break;
        }
        return num;
    }
};

int main()
{

    return 0;
}