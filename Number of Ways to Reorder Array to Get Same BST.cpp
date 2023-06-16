#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=_ZcQLiyQ3yM&t=14s

class Solution {
private:
    vector<vector<long long>> table;
    long long mod = 1e9 + 7;

    long long dfs(vector<int>& arr) {
        int n = arr.size();
        if(n <= 2) return 1;
        vector<int> left, right;
        int root = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] > root) right.push_back(arr[i]);
            else left.push_back(arr[i]);
        }
        long long leftVal = dfs(left) % mod;
        long long rightVal = dfs(right) % mod;
        return (((table[n - 1][left.size()] * leftVal) % mod) * rightVal) % mod;
    }

public:
    int numOfWays(vector<int>& nums) {
        long long mod = 1e9 + 7;
        int n = nums.size();
        table.resize(n + 1);
        for(int i = 0; i < n + 1; ++i){
            table[i] = vector<long long>(i + 1, 1);
            for(int j = 1; j < i; ++j){
                table[i][j] = (table[i-1][j-1] + table[i-1][j]) % mod;
            }
        }
        long long ans = dfs(nums);
        return (ans % mod - 1)%mod;
    }
};


int main(){

    return 0;
}