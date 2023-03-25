#include <bits/stdc++.h>
using namespace std;

// one approach is to use any ds such that you have the types of alphabets of the given string.
// After knowing the types for every type run the concept of Maximum Consecutive Ones III.


// Second approach :
// In this approach an vector is made to store the frequency of different alphabets in current window.
// The valid window is when **length of window - occurence of highest occurence alphabet in window <= k** . Means the less occuring alphabets total occurence must be less than k such that we can have a valid window.
// So for the purpose of finding the highest occurance alphabet in array we have to iterate the array for every window size which makes the algorithm O(26N).


// Third Approach
// The approach is similare to second approach but instead of iterating everytime for every window we are taking a variable max count so that we don't have to iterate through the array
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26);
        int maxCount = 0;
        
        int i = 0;
        int j = 0;
        
        int result = 0;
        
        while (j < s.size()) {
            count[s[j] - 'A']++;
            maxCount = max(maxCount, count[s[j] - 'A']);
            while(j - i + 1 - maxCount > k) {
                count[s[i] - 'A']--;
                i++;
            }
            result = max(result, j - i + 1);
            j++;
        }
        
        return result;
    }
};

int main(){

    return 0;
}