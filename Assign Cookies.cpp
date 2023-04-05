#include <bits/stdc++.h>
using namespace std;

// As we have to content as many children as possible so we first sort and try to content all children with least greed factor to high as, we start from least it will automatically return the max value.

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
            }
        }
        return sum;
    }
};

int main(){

    return 0;
}