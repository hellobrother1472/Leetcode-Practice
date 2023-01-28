#include <bits/stdc++.h>
using namespace std;

// Solving by creating and checking the sum of all the possible subsets of an imaginary vector with elements 1-9, to create this I am just taking a num which represents 1 at initial and then after every reccursion I am increasing the num until it get's > 9 so it is acting like I am iterating the vector. After that if sum == n and size of ds == k then it means it is the answer.

class Solution {
public:
    void helper(int k, int n, int num,int sum, vector<vector<int>>&ans, vector<int>&ds){
        if(sum == n && ds.size() == k){
            ans.push_back(ds);
            return;
        }
        if(num > 9 || ds.size() > k || sum > n) return;
        
        sum += num;
        ds.push_back(num);
        helper(k,n,num+1,sum, ans,ds);
        sum -= num;
        ds.pop_back();
        helper(k,n,num+1,sum, ans,ds);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
        helper(k,n,1,0,ans,ds);
        return ans;
    }
};

int main(){

    return 0;
}