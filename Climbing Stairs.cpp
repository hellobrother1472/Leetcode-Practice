#include <bits/stdc++.h>
using namespace std;

// Using reccursion
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 0){
            if(n == 0) return 1;
            return 0;
        }
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

// Using DP we just memoize the answer to avoid extra calls
class Solution {
public:
    unordered_map<int,int>memo;
    int climbStairs(int n) {
        if(n <= 0){
            if(n == 0) return 1;
            return 0;
        }
        if(!memo[n]) memo[n] = climbStairs(n-1) + climbStairs(n-2);
        return memo[n];
    }
};

int main(){

    return 0;
}