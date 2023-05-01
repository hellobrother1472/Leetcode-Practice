#include <bits/stdc++.h>
using namespace std;

// The approach is as follows:

// First, we find the LCS of the two given strings s1 and s2.
// We start with an empty string ans.
// We iterate over the characters of s1 and s2 one by one.
// For each character in s1, if the character is not part of the LCS, we add it to ans.
// For each character in s2, if the character is not part of the LCS, we add it to ans.
// Finally, we concatenate the LCS to ans and return it as the shortest common supersequence.

class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int len = dp[n][m];
        string ans;
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                ans += s1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) { // As we go upward j index remains same so add element at i
                ans += s1[i - 1];
                i--;
            } else { // As we go left i index remains same and j changes so add item at j index
                ans += s2[j - 1];
                j--;
            }
        }

        while (i > 0) {
            ans += s1[i - 1];
            i--;
        }

        while (j > 0) {
            ans += s2[j - 1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(){

    return 0;
}