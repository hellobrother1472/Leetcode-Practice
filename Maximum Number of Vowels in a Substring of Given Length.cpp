#include <bits/stdc++.h>
using namespace std;

// First count the vowels in initial window.
// After that for every one plus of window, if i is vowel so it is going to go out of window in next step so count--;
// if j's next is vowel means their is some new vowel going to add count++;
// Doing this we got our answer.
class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        unordered_map<char,int>mp;
        mp['a'] = 1;
        mp['e'] = 1;
        mp['i'] = 1;
        mp['o'] = 1;
        mp['u'] = 1;
        int i = 0, j = 0,ans = 0,count = 0;
        while(j < i+k){
            if(mp[s[j]]) count++;
            j++;
        }
        j--;
        while(j < n){
            ans = max(ans,count);
            if(mp[s[i]]) count--;
            if(j< n-1 && mp[s[j+1]]) count++;
            i++;
            j++; 
        }
        return ans;
    }
};

int main(){

    return 0;
}