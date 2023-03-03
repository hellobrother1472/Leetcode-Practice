#include <bits/stdc++.h>
using namespace std;

// We first reverse the string and then perform operation similar to "prefix to infix conversion". Just their is reverse in the parenthesis ( '(' --> ')' and vice versa ) as because we reverse the string.
// Logic is to push and push_back the parenthesis and operator whenever we got the operator and when we got the alphabet if st.top() is an operator then simply put out the alphabet with operator, if it is ')' the push_back '(' until we got the operator and then simply push_back operator also and continue.
// Then again reverse the answer.

class Solution {
  public:
    string postToInfix(string exp) {
        reverse(exp.begin(),exp.end());
        string ans = "";
        stack<char>st;
        for(int i = 0 ; i < exp.size() ; i++){
            if((exp[i]>=65 && exp[i] <=90) || (exp[i]>=97 && exp[i]<=122)){
                ans.push_back(exp[i]);
                if(!st.empty()){
                    if(st.top() != ')'){
                        ans.push_back(st.top());
                        st.pop();
                    }
                    else{
                        while(!st.empty() && st.top()== ')'){
                            ans.push_back('(');
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
                ans.push_back(')');
                st.push(')');
                st.push(exp[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Solution without reversing using way of '(' + stack one + operator + stack two + ')' 
bool isOperand(char x)
{
   return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}
class Solution2{
  public:
    string postToInfix(string exp){
        stack<string> s;
     
        for (int i=0; exp[i]!='\0'; i++)
        {
            // Push operands
            if (isOperand(exp[i]))
            {
               string op(1, exp[i]);
               s.push(op);
            }
     
            // We assume that input is
            // a valid postfix and expect
            // an operator.
            else
            {
                string op1 = s.top();
                s.pop();
                string op2 = s.top();
                s.pop();
                s.push("(" + op2 + exp[i] + op1 + ")");
            }
        }
     
        // There must be a single element
        // in stack now which is the required
        // infix.
        return s.top();
    }
};

int main(){

    return 0;
}