#include <bits/stdc++.h>
using namespace std;

// Similar to prefix to postfix just in it we are reversing in last

class Solution {
  public:
    string postToPre(string s) {
        // Write your code here
        string helper = "";
        stack<string>st;
        for(int i = 0 ; i < s.size(); i++){
            if((s[i]>=65 && s[i] <=90) || (s[i]>=97 && s[i]<=122)){
                string h = "";
                h.push_back(s[i]);
                st.push(h);
            }
            else{
                if(!st.empty()){
                    string h = "";
                    h += st.top();
                    helper += h;
                    st.pop();
                }
                if(!st.empty()){
                    string h = "";
                    h += st.top();
                    helper += h;
                    st.pop();
                }
                helper.push_back(s[i]);
                st.push(helper);
                helper = "";
            }
        }
        string ans = st.top();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    

    return 0;
}