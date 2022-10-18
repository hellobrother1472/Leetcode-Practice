#include <bits/stdc++.h>

using namespace std;

// Brute Force: Finding all possible permutations. Store it and find the next element of required.

// Using the cpp inbuilt function.

int main()
{
    int arr[] = {1, 3, 2};

    next_permutation(arr, arr + 3); // using in-built function of C++

    cout << arr[0] << " " << arr[1] << " " << arr[2];

    return 0;
}

// Most optimized approach
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size(), k, l;
        for (k = n - 2; k >= 0; k--)
        {
            if (nums[k] < nums[k + 1])
                break;
        }
        if (k < 0)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            for (l = n - 1; l > k; l--)
            {
                if (nums[l] > nums[k])
                    break;
            }
            swap(nums[k], nums[l]);
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};

int main()
{

    return 0;
}