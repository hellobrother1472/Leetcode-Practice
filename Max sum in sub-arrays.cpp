#include <bits/stdc++.h>

using namespace std;

// The logic is to just compare the two adjacent elements. Why I am not taking subarray of size > 2 is that because their can be two possiblity that whether the element is not second smallest (|5|1|6|) so in that case we can easily see that we can get value only using two size. And if it is smaller it means that the greater sum already exists for another subarray (|5|6|1|).
class Solution
{
public:
    long long pairWithMaxSum(long long arr[], long long N)
    {
        long long sum = INT_MIN;
        for (long long i = 1; i < N; i++)
        {
            if (sum < arr[i] + arr[i - 1])
                sum = arr[i] + arr[i - 1];
        }
        return sum;
    }
};

int main()
{

    return 0;
}