#include <bits/stdc++.h>
using namespace std;

// Logic used here is that roman numerals are usually written largest to smallest from left to right. We have to map the symbols and just add the values till the end.
// But their is a special case in which the m[i] < m[i+1], this breaks the largest to smallest, this breakage in roman numerals means that it is a single number whose value is m[i+1] - m[i] (It is used specifically for that purpose). 
// We don't have to check m[i+1] if i = n-1, so simlpy add the last symbol.

class Solution
{
public:
    int romanToInt(string s)
    {
        int n = s.length();
        // Mapping the values
        map<char, int> m; 
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int ans = 0;
        // Iterating and analysing what to add to ans.
        for (int i = 0; i < n; i++)
        {
            if (i == n - 1 || m[s[i]] >= m[s[i + 1]])
            {
                ans += m[s[i]];
            }
            else
            {
                int num = m[s[i + 1]] - m[s[i]];
                ans += num;
                i++;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}