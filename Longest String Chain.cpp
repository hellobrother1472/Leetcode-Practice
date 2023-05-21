#include <bits/stdc++.h>
using namespace std;

// Same as LIS just small change in condition.
class Solution {
private:
    bool helper(string& s1, string& s2){
        if(s1.size() != s2.size() + 1) return false;
        
        int first = 0;
        int second = 0;
        
        while(first < s1.size()){
            if(second < s2.size() && s1[first] == s2[second]){
                first ++;
                second ++;
            }
            else first ++;
        }
        if(first == s1.size() && second == s2.size()) return true;
        else return false; 
    }
    static bool cmp(string a, string b) {
        return a.length() < b.length();
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),cmp);
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (helper(words[i],words[j])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};


int main(){

    return 0;
}