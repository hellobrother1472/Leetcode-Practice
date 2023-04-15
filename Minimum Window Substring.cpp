#include <bits/stdc++.h>
using namespace std;

// Approach is correct but answer is not coming.
// This appraoch is same as - https://www.youtube.com/watch?v=iwv1llyN6mo

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()> s.size()) return "";
        string ans = s;

        map<char,int> mp, tracker,mp_clone,s_map;
        vector<int>v;
        
        for(int i = 0 ; i < t.size(); i++){
            mp[t[i]]++;
        }
        mp_clone = mp;
        // cout << mp.size() << endl;
        for(int i = 0 ; i < s.size(); i++){
            if(mp_clone[s[i]]>0){
                v.push_back(i);
                s_map[s[i]]++;
            }

        }
        // cout << mp.size() << endl;
        // cout << v.size() << endl;
        int i = 0, j = 0, k = 0, l = 0;
        if(s.size() == t.size() && mp == s_map) return s;
        else if(s.size() == t.size() && mp != s_map) return "";
        while(i < s.size() && j < s.size()){
            // cout << "l : " << l << " k : "<< k << endl;
            k = l;
            map<char,int> reverse = mp;
            while(k < v.size() && reverse.size() != 0){
                j = v[k];
                // cout << reverse.size();
                if(reverse[s[j]]){
                    reverse[s[j]]--;
                    if(reverse[s[j]] == 0) reverse.erase(s[j]);
                }
                tracker[s[j]]++;
                if(reverse.size() == 0) break;
                k++;
            }
            // cout << "tracker : " << tracker.size()<< endl;
            // cout << "First :  " << i << " and " << j << endl; 
            while(l < v.size() && tracker != mp){
                // cout << "here";
                i = v[l];
                if(tracker[s[i]]){
                    tracker[s[i]]--;
                    if(tracker[s[i]] == 0) tracker.erase(s[i]);
                }
                if(tracker == mp){ 
                    i = v[l+1];
                    l++;
                    break;
                };
                l++;
            }
            // cout<< "Second :  " << i << " and " << j << endl; 
            if(tracker == mp && ans.size() > j - i + 1){
                ans = "";
                int z = i;
                while(z != j){
                    ans.push_back(s[z]);
                    z++;
                }
                ans.push_back(s[z]);
            }
            // cout << ans << endl;
            tracker= reverse;
            l++;
            i = v[l];
            // cout << endl;
        }
        return ans;
    }
};

// This is correct solution
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        
        // Initialize a map to track the frequency of characters in t
        unordered_map<char, int> mp;
        for (char c : t) mp[c]++;
        
        int start = 0, end = 0, counter = mp.size();
        int minStart = 0, minLen = INT_MAX;
        
        // Loop through the string s
        while (end < s.size()) {
            char c = s[end];
            if (mp[c]) {  // If the character is in t
                mp[c]--;        // Decrement the frequency of the character in t
                if (mp[c] == 0) counter--;  // If the frequency becomes zero, decrement the counter
            }
            end++;
            
            // If all characters in t are found in the current window
            while (counter == 0) {
                if (end - start < minLen) {  // If the current window is shorter than the previous minimum
                    minStart = start;       // Update the minimum window start index
                    minLen = end - start;   // Update the minimum window length
                }
                
                char c = s[start];
                if (mp[c]) {  // If the character is in t
                    mp[c]++;        // Increment the frequency of the character in t
                    if (mp[c] > 0) counter++;  // If the frequency becomes positive, increment the counter
                }
                start++;
            }
        }
        
        return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
    }
};

int main(){

    return 0;
}