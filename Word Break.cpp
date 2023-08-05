#include <bits/stdc++.h>
using namespace std;

// Reccursive solution: Try putting the strings from the wordDict every possible combination. If we got the answer then return true;
class Solution {
private:
    bool helper(string s, vector<string>& wordDict, string temp){
        if(temp.size() > s.size()) return false;
        if(temp.size() == s.size()){
            if(s == temp) return true;
            return false;
        }
        for(int i = 0; i < wordDict.size(); i++){
            string t = temp;
            temp += wordDict[i];
            if(helper(s,wordDict,temp)) return true;
            temp = t;
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return helper(s,wordDict,"");
    }
};

// Reccursive 2
class Solution {
private:
    bool helper(int i,string s, vector<string>& wordDict) {
        if (i < 0) return true;        
        for (string word: wordDict) {
            int currSize = word.length();
            if (i - currSize + 1 < 0) continue;
            if (s.substr(i - currSize + 1, currSize) == word && helper(i - currSize,s,wordDict)) return true;
        }
        return false;
    }
public:    
    bool wordBreak(string s, vector<string>& wordDict) {
        return helper(s.length() - 1,s,wordDict);
    }    
};

// DP - 1 Memoization
class Solution {
private:
    // Recursive helper function to check if a substring of 's', starting from index 'i', can be segmented into words from 'wordDict'.
    // Returns true if the substring can be segmented, false otherwise.
    bool helper(int i,string s, vector<string>& wordDict,vector<int>&dp) {
        // Base case: If we reach the end of the string, it means we successfully segmented the string.
        if (i == s.length()) return true;
        // If the result for this index has already been computed, return it.
        if (dp[i] != -1) return dp[i] == 1;

        // Try to segment the remaining part of the string starting from index 'i'.
        for (string word : wordDict) {
            int currSize = word.length();
            // Check if the current word matches a substring starting from index 'i'.
            // If it does, and the remaining part of the string can be segmented (helper(i + currSize) is true),
            // then we can successfully segment the string from index 'i'.
            if (i + currSize <= s.length() && s.substr(i, currSize) == word && helper(i + currSize,s,wordDict,dp)) {
                // Mark the result for this index as 1 (true).
                dp[i] = 1;
                return true;
            }
        }

        // If we cannot segment the string starting from index 'i', mark the result as 0 (false).
        dp[i] = 0;
        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.length(), -1);
        return helper(0,s,wordDict,dp);
    }
};



// DP-Memoization
class Solution {
private:
    vector<int> memo;
    vector<string> wordDict;
    string s;
    bool helper(int i) {
        if (i < 0) return true;        
        if (memo[i] != -1) return memo[i] == 1;        
        for (string word: wordDict) {
            int currSize = word.length();
            if (i - currSize + 1 < 0) continue;
            if (s.substr(i - currSize + 1, currSize) == word && helper(i - currSize)) {
                memo[i] = 1;
                return true;
            }
        }        
        memo[i] = 0;
        return false;
    }
public:    
    bool wordBreak(string s, vector<string>& wordDict) {
        memo = vector<int>(s.length(), -1);
        this->wordDict = wordDict;
        this->s = s;
        return helper(s.length() - 1);
    }
    
};

// Tabularization - 1

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        int wordDictSize = wordDict.size();

        // dp[i] will store whether the substring s[i:n] can be segmented into words from the wordDict.
        std::vector<bool> dp(n + 1, false);
        dp[n] = true; // An empty string can always be segmented.

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < wordDictSize;j++) {
                int currSize = wordDict[j].length();
                // Check if s[i:i+currSize] (substring from i to i+currSize-1) is equal to wordDict[j]
                // and if dp[i+currSize] is true (substring s[i+currSize:n] can be segmented).
                if (i + currSize <= n && s.substr(i, currSize) == wordDict[j] && dp[i + currSize]) {
                    dp[i] = true;
                    break; // Break the inner loop as we found a valid segmentation for s[i:n].
                }
            }
        }

        return dp[0]; // Return whether the entire string can be segmented.
    }
};

// Tabularization - 2
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length());
        for (int i = 0; i < s.length(); i++) {
            for (string word: wordDict) {
                // Handle out of bounds case
                if (i < word.length() - 1) {
                    continue;
                }
                
                if (i == word.length() - 1 || dp[i - word.length()]) {
                    if (s.substr(i - word.length() + 1, word.length()) == word) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[s.length() - 1];
    }
};

int main(){

    return 0;
}