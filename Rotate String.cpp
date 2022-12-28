#include <bits/stdc++.h>
using namespace std;

// Using two pointers i and j, by using it I am searching the same string as long as I am getting the same string I am increasing both i and j and if their is any disturbance then I take I back to 0 (because it's voilates).
// After reaching the last of the j iterator (first while loop) I know that if i>0 it means I get same substring, so after that keeping the i at it prev place and making j = 0, now on all the char should be same as I got the point from previous while loop.
// if i == 0, it means we still not get the substring,so first we try to solve the question by reversing s and goal. For counting that their is flag. After that if at second chance i = 0, then just return false.

// O(n) Approach
class Solution
{
public:
    int flag = 0; // For counting
    bool rotateString(string s, string goal)
    {
        int sl = s.length();
        int gl = goal.length();
        if (sl != gl)
            return false;
        int i = 0, j = 0;

        while (j < gl) // First while loop for getting that same small substring
        {
            if (s[i] == goal[j])
            {
                i++;
            }
            else
            {
                if (j != gl - 1)
                    i = 0;
            }
            j++;
        }
        j = 0;
        if (i == 0) // conditions for i = 0
        {
            flag++;
            if (flag == 1)
                return rotateString(goal, s);
            else
                return false;
        }

        for (i; i < sl; i++, j++) // checking that now on chars should be same.
        {
            if (s[i] != goal[j])
                return false;
        }
        return true;
    }
};

int main()
{
    return 0;
}