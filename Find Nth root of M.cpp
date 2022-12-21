#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int NthRoot(int n, int m)
    {
        int start = 0, end = m;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            auto num = pow(mid, n);
            if (num == m)
            {
                return mid;
            }
            else if (num > m)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }
};

int main()
{

    return 0;
}