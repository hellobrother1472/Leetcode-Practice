#include <bits/stdc++.h>
using namespace std;

// Same approach as koko eating bananas with change in validate function according to the condition.
class Solution
{
public:
    int maxVal(vector<int> weights, int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += weights[i];
        return sum;
    }

    bool validate(vector<int> weights, int days, int num, int n)
    {
        int temp = num;
        for (int i = 0; i < n && days > 0; i++)
        {
            if (weights[i] <= temp)
            {
                temp -= weights[i];
                weights[i] = 0;
            }
            else
            {
                temp = 0;
                i--;
            }
            if (temp == 0)
            {
                days--;
                temp = num;
            }
        }
        if (weights[n - 1] == 0)
            return true;
        return false;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int n = weights.size();
        long long maxWeight = (long long)maxVal(weights, n);
        int start = 1, end = maxWeight, ans = maxWeight;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            bool validateVal = validate(weights, days, mid, n);
            if (validateVal)
            {
                if (mid < ans)
                    ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}