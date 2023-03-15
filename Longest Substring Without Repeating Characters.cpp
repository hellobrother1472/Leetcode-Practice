#include <bits/stdc++.h>
using namespace std;

//  We will have two pointers left and right. Pointer ‘left’ is used for maintaining the starting point of the substring while ‘right’ will maintain the endpoint of the substring.’ right’ pointer will move forward and check for the duplicate occurrence of the current element if found then the ‘left’ pointer will be shifted ahead so as to delete the duplicate elements.
// we will make a map that will take care of counting the elements and maintaining the frequency of each and every element as a unity by taking the latest index of every element.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        int n = s.length();
        map<char,int>m;
        m[s[0]]++;
        int i = 0, j = 1, ans = 1;
        while(j < n && i < n){
            m[s[j]]++;
            if(m[s[j]] > 1 ){
                while(i <= j && m[s[j]] > 1){
                    m[s[i]]--;
                    i++;
                }
            }
            if(j-i+1 > ans) ans = j-i+1;
            j++;
        }
        return ans;
    }
};


int main(){

    return 0;
}