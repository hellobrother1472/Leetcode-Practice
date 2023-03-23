#include <bits/stdc++.h>
using namespace std;

// In while loop I am first increasing j until I get a valid substring, valid substring is checked by isValid() function which iterate through the v vector and return false if any of the element is zero. If after this first while loop the substring is still not valid then it means their is no further valid substring left so return ans.

// Then I increase the i until the substring is valid, the idea is to find minimum length valid substring out of the valid substring and along with that the lCount is increasing (which counts elements on left).

// rCount is all the elements on right of j. Then calulate by formula ans += (lCount+1)*(rCount+1)

class Solution {
public:
    bool isValid(vector<int>v){
        for(int i = 0; i < v.size();i++){
            if(v[i] == 0) return false;
        }
        return true;
    }

    int numberOfSubstrings(string s) {
        vector<int>v(3);
        for(int i = 0; i < v.size();i++) v[i] = 0; // Making all elements zero
        int i = 0, j = 0 , n = s.size(), lCount = 0, rCount = 0, ans = 0;

        while(i<n && j<n){
            
           while(j < n && !isValid(v)){
               v[s[j]-'a']++;
               j++;
           }
           j--; // Adjustment made as due to while loop j reaches one index ahead

           if(!isValid(v) )return ans;

           while(i<n && j< n && isValid(v)){
               v[s[i]-'a']--;
               lCount++;
               i++;
           }
            // Adjusting the count, v[i] and i as due to while loop it gets one index ahead.    
           i--;
           v[s[i]-'a']++;
           lCount--;

            // Adding into the answer.
           rCount = n - j - 1;
           ans += (lCount+1)*(rCount+1);

            // Now increasing i and j for finding next substirng and adjusting related values for next iteration.
           v[s[i]-'a']--;
           i++;
           j++;
           lCount = 0;
           rCount = 0;

        }
        return ans;
    }
};

int main(){

    return 0;
}