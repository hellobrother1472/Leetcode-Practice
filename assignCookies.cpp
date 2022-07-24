#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int sum = 0;
        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (j < g.size())
            {
                if (s[i] >= g[j])
                {
                    j++;
                    sum++;
                }
                else
                {
                    continue;
                }
            }
        }
        return sum;
    }
};

int main()
{

    return 0;
}