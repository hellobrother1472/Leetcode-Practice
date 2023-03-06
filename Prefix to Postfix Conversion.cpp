#include <bits/stdc++.h>
using namespace std;

// Studied from https://youtu.be/jZxII0guwUo
// The idea is to reverse the given string and then tranversing
// While traversing if thier is an alphabet then push it to stack and if the operator comes then perform below operation
// stack first (and then pop) + stack second (and then pop) + operator and then push this new string again.
class Solution {
  public:
    string preToPost(string s) {
        reverse(s.begin(), s.end());
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
        return st.top();
    }
};

int main(){
    

    return 0;
}