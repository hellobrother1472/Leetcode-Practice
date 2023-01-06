#include <bits/stdc++.h>
using namespace std;

// Intution is that as we have to return minimum rounds required to complete all the tasks, and we can only do 2 or 3 tasks at a time. I am storing the answer in map. And then I am taking the max condition of 3 task at a time so that I can complete the tasks in minimum time.
// So while dividing the total number of given task of given difficulty I can get different reminders. So I made an helper function which helps me to return answer on the base of the number. And I am simply adding it to answer.
// If num in helper is 1 then return -1 because we can't do this task as we can strictly do only 2 or 3 tasks in one round. 

class Solution
{
public:
    int helper(int num)
    {
        if (num == 1 || num < 0)
            return -1;

        if (num == 2)
        {
            return 1;
        }
        else if (num == 0)
        {
            return 0;
        }
        else
        {
            if (num % 3 == 0)
            {
                return num / 3;
            }
            else if (num % 3 == 1)
            {
                int temp = helper(num - 4); // (num-4)/3
                return temp + 2;
            }
            else
            {
                return num / 3 + 1;
            }
        }
        return 0;
    }
    int minimumRounds(vector<int> &tasks)
    {
        map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < tasks.size(); i++)
            mp[tasks[i]]++;
        for (auto i : mp)
        {
            int temp = helper(i.second);
            if (temp == -1)
                return -1;
            ans += temp;
        }
        return ans;
    }
};

int main()
{

    return 0;
}