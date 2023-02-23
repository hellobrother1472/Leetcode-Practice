#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        int a = 1 << k;
        return n&a;
    }
};

int main(){

    return 0;
}