#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < bills.size(); i++)
        {
            mp[bills[i]]++;
            if (bills[i] != 5)
            {
                int remains = (bills[i] - 5);
                while (mp[20] > 0 && remains >= 20)
                {
                    remains -= 20;
                    mp[20]--;
                }
                while (mp[10] > 0 && remains >= 10)
                {
                    remains -= 10;
                    mp[10]--;
                }
                while (mp[5] > 0 && remains >= 5)
                {
                    remains -= 5;
                    mp[5]--;
                }
                if (remains > 0)
                    return false;
            }
        }
        return true;
    }
};

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0, ten = 0;
        for (int bill : bills)
        {
            if (bill == 5)
                five++;
            else if (bill == 10)
            {
                if (five == 0)
                    return false;
                five--;
                ten++;
            }
            else
            {
                if (five > 0 && ten > 0)
                {
                    five--;
                    ten--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{

    return 0;
}