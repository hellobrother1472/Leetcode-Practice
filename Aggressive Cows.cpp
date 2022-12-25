#include <bits/stdc++.h>
using namespace std;

// Intution : the solution can be founded out by checking all the possible gaps which is in between 1 and stalls[n - 1] - stalls[0](max distace possible between 2).
// So by applying binary search on the range we get mid val, then I validate it to be valid or not if not valid it means that this gap is large so I decreases the array by doing end = mid - 1; if it is validated then according to question I have to search for higher val so I did start = mid + 1.    

class Solution
{
public:
    bool validate(int n, int k, vector<int> stalls, int num)
    {
        int i = 0, j = i + 1;
        k--; // as putting on stalls[0] and then checking for others.
        while (i < n && j < n)
        {
            if (stalls[j] - stalls[i] >= num) // if gap is >= nums then put cow in it and start counting diff from their
            {
                k--;
                i = j;
                j++;
            }
            else
                j++;
        }
        if (k <= 0) // if at last no. of cows is <=0 then it means all the cows are placed so it is valid (true)
            return true;
        return false;
    }
    int solve(int n, int k, vector<int> &stalls)
    {
        sort(stalls.begin(), stalls.end()); // nlog(n) sorting because we have to calculate the diff.
        int start = 1, end = stalls[n - 1] - stalls[0], ans = 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            int vali = validate(n, k, stalls, mid);
            if (vali)
            {
                if (mid >= ans)
                    ans = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
            return ans;
        }
    }
};

int main()
{
    return 0;
}