#include <bits/stdc++.h>
using namespace std;

// O(n^3) approach : check every possible string to be a palindrom and update ans and at last ans will have largest possible palindrom stirng return;
class Solution {
public:
    string checkPalindrom(int i, int j, string s){
        string org = "";
        string temp = "";
        for(int k = j; k >= i; k--){
            temp += s[k];
        }
        for(int k = i; k <= j; k++){
            org += s[k];
        }
        if(org == temp){
            return org;
        }
        return "false";
    }
    string longestPalindrome(string s) {
        
        int n = s.length();
        int i = 0;
        int j = n-1;
        string ans = "";
        if(s.length() == 1){
            return s;
        }
        // int len = j-i+1;
        while(i<j){
            // cout << i << " and " << j << endl;
            // cout << "value of ans is "<< ans<< endl;
            if(n-i < ans.size()){
                // cout << "here 1";
                break;
            }
            string sol = checkPalindrom(i,j,s);
            if(sol != "false"){
                if(sol.length() > ans.length()){
                    ans = sol;
                    i++;
                    j = n-1;
                    continue;
                }
            }
            j--;
            if(i==j || j-i+1 <= ans.length()){
                i++;
                j = n-1;
                continue;
            }
        }
        if(ans == ""){
            ans+= s[0];
        }
        return ans;
    }
};

// O(n^2) (Without DP) - Explaination - https://leetcode.com/problems/longest-palindromic-substring/solutions/2922768/simple-o-n-2-solution-with-detailed-explaination/?languageTags=cpp&topicTags=string%2Ctwo-pointers%2Csliding-window

// In this approach after getting to every element we are expanding in outwards direction until s[left] == s[right], and updating the answer according to length.

class Solution {
public:
    string longestPalindrome(string s) {
        //Initialising a variable storing the maxLength
        int maxLength = 0;
        //Initialising a pair to store the start and end indices of longest palindromic subsrting
        pair<int,int> indices;

        for(int i = 0; i < s.size(); i++){
            //declaring the length variable to measure length of each substring
            int length;

            // ODD Length Case of Palindromic Substring
            // initialising left to i (current index)
            int left = i;
            // same goes for right
            int right = i;
            // while we are able to expand and the substring remains palindromic
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                length = (right - left + 1);
                // Comparing the Length to maxLength and updating the maxLength & 
                // indices if the length of current palindromic substring is greater
                // than the previous largest palindromic substring
                if(length > maxLength){
                    maxLength = length;
                    indices.first = left;
                    indices.second = right;
                }

                left--; //expanding towards left
                right++; //expanding towards right
            }

            // EVEN Length Case of Palindromic Substring
            // Intialising left to i (current Index)
            left = i;
            // notice here we will not initialise right
            // the same as left but as left+1, which will
            // automatically make the length as 2 (EVEN) before 
            // the execution of the loop
            right = left + 1;
            // Again Expanding both the sides until we are able to.
            // Notice how here with each iteration the length will
            // always be EVEN
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                // doing the same task as before

                length = (right - left + 1);
                
                if(length > maxLength){
                    maxLength = length;
                    indices.first = left;
                    indices.second = right;
                }
                left--;
                right++; 
                // Length will remain even here since we must expand to both
                // the sides at once only
            }
        }

        // return the substring having largest length & is palindromic with the
        // help of the indices we stored earlier
        // we practically never used indices.second because
        // we did the job of printing subString with the help
        // of c++ inbuilt substr function which required length
        return s.substr(indices.first, maxLength);
    }
};

int main(){

    return 0;
}