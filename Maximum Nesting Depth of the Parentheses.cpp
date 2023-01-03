#include <bits/stdc++.h>
using namespace std;

// Approach is to count the stack size because as the nesting increases the stack size increases. So getting the highest stack size is the answer.

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        stack<char>st;
        for(int i = 0 ; i < s.length() ; i++){
            
            if(s[i] == '('){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                st.pop();
            }
            
            if(ans < st.size()){
                ans = st.size();
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}