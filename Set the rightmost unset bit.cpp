#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int setBit(int n)
    {
        // Write Your Code here
        if (!(n & (n + 1))) return n;
        return n | (n + 1);
    }
};

int main(){
    

    return 0;
}