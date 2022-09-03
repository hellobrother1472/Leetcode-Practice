#include <iostream>
// #include <bits/stdc++.h>
#include <limits.h>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {

        bool neg = false;
        if (x < 0)
        {
            neg = true;
            x = abs(x);
        }

        long long reverse = 0;
        while (x > 0)
        {

            int digit = x % 10;
            reverse = reverse * 10 + digit;
            x = x / 10;
        }
        if (reverse < INT_MIN || reverse > INT_MAX)
        {
            return 0;
        }
        if (neg)
        {
            return reverse * (-1);
        }
        return reverse;
    }
};

int main()
{

    return 0;
}