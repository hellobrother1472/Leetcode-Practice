#include <bits/stdc++.h>
using namespace std;

// In question we have to find the min possible max pages of distribution from all permutation. So the answer can be in range lowest num in array and sum of array.
// Now to design the validate function I have to check that the number of pages one student get should be less than num which is mid value we got, and now I am counting the no. of students in which it can now be distributed and then checking the value at the last.
// And on the base of validation the decision of moving the pointers is taken.

class Solution
{
public:
    int findSum(int A[], int N)
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += A[i];
        }
        return sum;
    }
    bool validate(int a[], int n, int m, int num)
    {
        int total = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (sum + a[i] <= num)
                sum += a[i];
            else
            {
                if (a[i] > num)
                    return false;
                total++;
                sum = 0;
                sum += a[i];
            }
        }
        if (total < m)
            return true;
        return false;
    }
    int findMin(int a[], int n)
    {
        int min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (min > a[i])
                min = a[i];
        }
        return min;
    }
    int findPages(int a[], int n, int m)
    {
        if (m > n)
            return -1;
        int sum = findSum(a, n);
        if (m == 1)
            return sum;
        int start = findMin(a, n), end = sum, ans = sum;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            bool validation = validate(a, n, m, mid);
            if (validation)
            {
                if (mid < ans)
                    ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return ans;
    }
};

int main()
{

    return 0;
}