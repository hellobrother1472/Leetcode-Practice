#include <bits/stdc++.h>
using namespace std; 

// I see that the number of "(" and ")" should be n both. So the base condition is if temp.length() == 2*n then put it in the ans and return.
// Their is one observation that we can have as many "(" upto the limit but ")" is dependent on no. of "(", "(">=")". So I am applying same condition on openCount and closeCount.
class Solution {
public:
    vector<string>ans;
    string temp = "";
    int openCount = 1, closeCount = 0;
    void helper(int n, int i){
        if(temp.length() == 2*n){
            ans.push_back(temp);
            return;
        }
        if(openCount < n){
            temp.push_back('(');
            openCount++;
            helper(n,i+1);
            temp.pop_back();
            openCount--;
        }
        if(closeCount < n && closeCount < openCount){
            temp.push_back(')');
            closeCount++;
            helper(n,i+1);
            temp.pop_back();
            closeCount--;
        }
    }
    vector<string> generateParenthesis(int n) {
        temp.push_back('(');
        helper(n, 0);
        return ans;
    }
};

class Solution {
public:
    vector<string>ans;
    string temp = "";
    void helper(int n, int i, int openCount, int closeCount){
        if(temp.length() == 2*n){
            ans.push_back(temp);
            return;
        }
        if(openCount < n){
            temp.push_back('(');
            helper(n,i+1,openCount+1,closeCount);
            temp.pop_back();
        }
        if(closeCount < n && closeCount < openCount){
            temp.push_back(')');
            helper(n,i+1,openCount,closeCount+1);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        temp.push_back('(');
        helper(n, 0,1,0);
        return ans;
    }
};

int main(){

    return 0;
}