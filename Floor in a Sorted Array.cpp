#include <iostream>
#include <vector>

using namespace std;

int findFloor(vector<long long> v, long long n, long long x)
{

    // Your code here
    if (v[0] > x)
        return -1;
    int start = 0, end = n - 1;
    int ans = start;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (v[mid] == x)
        {
            return mid;
        }
        else if (v[mid] > x)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
            ans = start - 1;
        }
    }
    return ans;
}

int main()
{

    return 0;
}