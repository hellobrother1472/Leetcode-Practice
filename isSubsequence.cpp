#include <iostream>
#include <string>
#include <map>

using namespace std;

// Using Two Pointers (Meathod 1)
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int n = s.length(), m = t.length();
        int j = 0;

        for (int i = 0; i < m and j < n; i++)
        {
            if (s[j] == t[i])
            {
                j++;
            }
        }
        return (j == n);
    }
};

// Using Two Pointers (Meathod 2)
class Solution2
{
public:
    bool isSubsequence(string s, string t)
    {
        if (s.size() == 0)
        {
            return true;
        }
        if (s.size() == 0 || s.size() > t.size())
        {
            return false;
        }

        int i = 0, j = 0;
        while (j < t.size())
        {
            if (s[i] == t[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }

        if (i >= s.size())
        {
            return true;
        }

        return false;
    }
};

int main()
{
    string a = "hello";
    cout << a.size();

    return 0;
}