#include <bits/stdc++.h>
using namespace std;

// Intution is to take the max value of the vector and then we got our max number of day. Applying binary search on range of 1 to maxDays days. In binary search we are first modifing the vector and then validating it. If validated then I try to find less no. of days by high = mid - 1 and if it is not validated then I move forward by making low = mid+1. At last I got the ans.

class Solution
{
public:
    int maxOfVector(vector<int> v)
    { // Finding the max number in a vector.
        int max = INT_MIN;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] > max)
                max = v[i];
        }
        return max;
    }

    vector<int> modify(vector<int> bloomDay, int day) // Day is the number which I get from using binary search and I am checking that on that day which flower I can take. So I am marking it by putting it -2.
    {
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= day)
                bloomDay[i] = -2;
        }
        return bloomDay;
    }

    bool validate(vector<int> v, int k, int m) // Here I am validating the condition that I have to take k adjecent flowers. So for every k adjecent flower I am increasing count and checking the count value if it is equal to m or not and giving bool value.
    {
        int count = 0;
        int tempCount = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == -2)
            {
                tempCount++;
            }
            else
            {
                tempCount = 0;
            }
            if (tempCount == k)
            {
                tempCount = 0;
                count++;
            }
        }

        if (count >= m)
        {
            return true;
        }
        return false;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        long long n = bloomDay.size();
        int maxOfVec = maxOfVector(bloomDay);
        unsigned long long totalFlower = (long long)m * k;
        if (n < totalFlower)
            return -1;
        if (n == totalFlower)
            return maxOfVec;

        int start = 1, end = maxOfVec, ans = maxOfVec;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            vector<int> arr = modify(bloomDay, mid); // modified vector
            bool val = validate(arr, k, m);
            if (val)
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