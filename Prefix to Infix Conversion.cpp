#include <bits/stdc++.h>
using namespace std;

// Approach :- While traversing the given string if I come accross an operator we simply store it to the stack, otherwise when I get an alphabet I will push it in answer with the stack's top element (Operator) and then pop the top element.

// This solution is without parenthesisation
class Solution {
  public:
    string preToInfix(string s) {
        string ans = "";
        stack<char> st;
        for(int i = 0 ; i < s.size(); i++){
            if((s[i]>=65 && s[i] <=90) || (s[i]>=97 && s[i]<=122)){
                ans.push_back(s[i]);
                if(!st.empty()){
                    char ch = st.top();
                    st.pop();
                    ans.push_back(ch);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        return ans;
    }
};

// Solution with parenthization
// Logic is to push and push_back the parenthesis and operator whenever we got the operator and when we got the alphabet if st.top() is an operator then simply put out the alphabet with operator, if it is '(' the push_back ')' until we got the operator and then simply push_back operator also and continue.
class Solution {
  public:
    string preToInfix(string s) {
        string ans = "";
        stack<char> st;
        for(int i = 0 ; i < s.size(); i++){
            if((s[i]>=65 && s[i] <=90) || (s[i]>=97 && s[i]<=122)){

                ans.push_back(s[i]);

                if(!st.empty()){
                    if(st.top() != '('){
                        ans.push_back(st.top());
                        st.pop();
                    }
                    else{
                        while(!st.empty() && st.top()== '('){
                            ans.push_back(')');
                            st.pop();
                        }
                        if(!st.empty()){
                            ans.push_back(st.top());
                            st.pop();
                        }
                    }
                }

            }
            else{
                ans.push_back('(');
                st.push('(');
                st.push(s[i]);
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}