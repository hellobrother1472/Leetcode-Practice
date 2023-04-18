#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int i = 0, j = 0;
        while(i < word1.size() && j < word2.size()){
            ans.push_back(word1[i]);
            ans.push_back(word2[j]);
            i++;
            j++;
        }

        for(int k = i; k < word1.size(); k++){
            ans.push_back(word1[k]);
        }
        for(int k = j; k < word2.size(); k++){
            ans.push_back(word2[k]);
        }
        return ans;
    }
};

// Short code
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        string result = "";
        int i = 0, j = 0;

        while (i < m || j < n) {
            if (i < m) {
                result.push_back(word1[i++]);
            }
            if (j < n) {
                result.push_back(word2[j++]);
            }
        }

        return result;
    }
};

// Using one pointer
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        string result = "";

        for (int i = 0; i < max(m, n); i++) {
            if (i < m) {
                result.push_back(word1[i]);
            }
            if (i < n) {
                result.push_back(word2[i]);
            }
        }

        return result;
    }
};

int main(){

    return 0;
}