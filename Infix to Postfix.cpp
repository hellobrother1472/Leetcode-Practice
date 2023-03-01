#include <bits/stdc++.h>
using namespace std;

// set the precedence and if current element precedence is high so push it other wise pop out all the elements until it get's greter than stack top. In case of ( we normally push and perform similar operation but as ) comes we pop out all the elements until ( comes.

class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        map<char,int> m;
        m['+'] = 1;
        m['-'] = 1;
        m['*'] = 2;
        m['/'] = 2;
        m['^'] = 3;
        string ans = "";
        stack<int>st;
        int i = 0;
        while(i < s.size()){
            if((s[i]>=65 && s[i] <=90) || (s[i]>=97 && s[i]<=122)){
                ans.push_back(s[i]);
                i++;
                continue;
            }
            if (s[i] == ')'){
                while(st.top() != '('){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            else if(st.empty() || s[i] == '('|| m[s[i]] > m[st.top()]|| st.top() == '('){
                st.push(s[i]);
            }
            else if(m[s[i]] <= m[st.top()]){
                while(!st.empty() && m[s[i]] <= m[st.top()]){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(s[i]);
            }
            
            i++;
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
        
    }
};

int main(){

    return 0;
}