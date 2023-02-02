#include <bits/stdc++.h>
using namespace std;

// Answer is correct but time limit exceeds
class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        if (len == 0) return 0;
        stack<int> stack;
        int currentNumber = 0;
        char operation = '+';
        for (int i = 0; i < len; i++) {
            char currentChar = s[i];
            if (isdigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!isdigit(currentChar) && !iswspace(currentChar) || i == len - 1) {
                if (operation == '-') {
                    stack.push(-currentNumber);
                } else if (operation == '+') {
                    stack.push(currentNumber);
                } else if (operation == '*') {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop * currentNumber);
                } else if (operation == '/') {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop / currentNumber);
                }
                operation = currentChar;
                currentNumber = 0;
            }
        }
        int result = 0;
        while (stack.size() != 0) {
            result += stack.top();
            stack.pop();
        }
        return result;
    }
    void helper(string num, int target, int val, vector<string>&ans, string temp, int index){
        if(index == num.size() && val == target){
            ans.push_back(temp);
            return;
        }
        if(index >= num.size()) return;
        
        if(val < target){
            // plus
            temp.push_back('+');
            temp.push_back(num[index]);
            val = calculate(temp);
            helper(num,target,val,ans,temp,index+1);
            temp.pop_back();
            temp.pop_back();

            // multiply
            temp.push_back('*');
            temp.push_back(num[index]);
            val = calculate(temp);
            helper(num,target,val,ans,temp,index+1);
            temp.pop_back();
            temp.pop_back();
        }        

        // minus
        temp.push_back('-');
        temp.push_back(num[index]);
        val = calculate(temp);
        helper(num,target,val,ans,temp,index+1);
        temp.pop_back();
        temp.pop_back();

        // For not doing something
        temp.push_back(num[index]);
        val = calculate(temp);
        helper(num,target,val,ans,temp,index+1);
        temp.pop_back();
        
    }
    vector<string> addOperators(string num, int target) {
        vector<string>ans;
        string temp = "";
        temp.push_back(num[0]);
        int val = num[0] -'0';
        helper(num,target,val,ans,temp,1);
        return ans;
    }
};

// Here val is calculated only when index gets equal to size(). 
class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        if (len == 0) return 0;
        stack<int> stack;
        int currentNumber = 0;
        char operation = '+';
        for (int i = 0; i < len; i++) {
            char currentChar = s[i];
            if (isdigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!isdigit(currentChar) && !iswspace(currentChar) || i == len - 1) {
                if (operation == '-') {
                    stack.push(-currentNumber);
                } else if (operation == '+') {
                    stack.push(currentNumber);
                } else if (operation == '*') {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop * currentNumber);
                } else if (operation == '/') {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop / currentNumber);
                }
                operation = currentChar;
                currentNumber = 0;
            }
        }
        int result = 0;
        while (stack.size() != 0) {
            result += stack.top();
            stack.pop();
        }
        return result;
    }
    void helper(string num, int target, vector<string>&ans, string temp, int index){
        if(index == num.size()){
            long long val = calculate(temp);
            if(target == val){
                ans.push_back(temp);
            }
            return;
        }
        
        // plus
        temp.push_back('+');
        temp.push_back(num[index]);
        helper(num,target,ans,temp,index+1);
        temp.pop_back();
        temp.pop_back();

        // multiply
        temp.push_back('*');
        temp.push_back(num[index]);
        helper(num,target,ans,temp,index+1);
        temp.pop_back();
        temp.pop_back();

        // minus
        temp.push_back('-');
        temp.push_back(num[index]);
        helper(num,target,ans,temp,index+1);
        temp.pop_back();
        temp.pop_back();

        // For not doing something
        temp.push_back(num[index]);
        helper(num,target,ans,temp,index+1);
        temp.pop_back();
        
    }
    vector<string> addOperators(string num, int target) {
        vector<string>ans;
        string temp = "";
        temp.push_back(num[0]);
        int val = num[0] -'0';
        helper(num,target,ans,temp,1);
        return ans;
    }
};



class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        recursion(ans, num, target, "", 0, 0, 0 );
        return ans;
    }
    
    void recursion(vector<string>& ans, const string& num, const int& target, string expression, int idx, int prevNum, long long curTotal){
        int n = num.size();
        if(idx==n){
            if(curTotal==target){
                ans.push_back(expression);
            }
            return;
        }
        string curNumStr = "";
        long long curNum = 0;
        for(int i = idx; i<n; i++){
            if(i>idx && num[idx]=='0')break;
            curNumStr+=num[i];
            curNum = curNum*10+(num[i]-'0');
            // 2345
            if(idx==0){
                recursion(ans, num, target, expression+curNumStr, i+1, curNum, curTotal+curNum);
            }
            else{
                recursion(ans, num, target, expression+"+"+curNumStr, i+1, curNum, curTotal+curNum);
                recursion(ans, num, target, expression+"-"+curNumStr, i+1, -curNum, curTotal-curNum);
                recursion(ans, num, target, expression+"*"+curNumStr, i+1, prevNum*curNum, curTotal-prevNum+prevNum*curNum);
            }
        }
    }
    
};



int main(){
    

    return 0;
}