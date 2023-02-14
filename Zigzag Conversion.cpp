#include <bits/stdc++.h>
using namespace std;

// Logic is to make a iterator or tracker like num which is capable of moving both forward and backward. The condition of val which is changing it's bool value at two extreame it is helping in decision making.
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        vector<string> helper(numRows);
        int num = 1, i = 0;
        bool val = true;
        while (i < s.size())
        {
            helper[num - 1].push_back(s[i]);
            i++;

            // Setting the value of val
            if (num == 1) val = true;
            if (num == numRows) val = false;

            // According to val taking decision
            if (val) num++;
            else num--;
        }
        // combining the answer
        string ans = "";
        for (int j = 0; j < helper.size(); j++)
        {
            ans += helper[j];
        }
        return ans;
    }
};

int main()
{

    return 0;
}