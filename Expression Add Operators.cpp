#include <bits/stdc++.h>
using namespace std;

// Answer is correct but time limit exceeds
class Solution
{
public:
    int calculate(string s)
    {
        int len = s.length();
        if (len == 0)
            return 0;
        stack<int> stack;
        int currentNumber = 0;
        char operation = '+';
        for (int i = 0; i < len; i++)
        {
            char currentChar = s[i];
            if (isdigit(currentChar))
            {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!isdigit(currentChar) && !iswspace(currentChar) || i == len - 1)
            {
                if (operation == '-')
                {
                    stack.push(-currentNumber);
                }
                else if (operation == '+')
                {
                    stack.push(currentNumber);
                }
                else if (operation == '*')
                {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop * currentNumber);
                }
                else if (operation == '/')
                {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop / currentNumber);
                }
                operation = currentChar;
                currentNumber = 0;
            }
        }
        int result = 0;
        while (stack.size() != 0)
        {
            result += stack.top();
            stack.pop();
        }
        return result;
    }
    void helper(string num, int target, int val, vector<string> &ans, string temp, int index)
    {
        if (index == num.size() && val == target)
        {
            ans.push_back(temp);
            return;
        }
        if (index >= num.size())
            return;

        if (val < target)
        {
            // plus
            temp.push_back('+');
            temp.push_back(num[index]);
            val = calculate(temp);
            helper(num, target, val, ans, temp, index + 1);
            temp.pop_back();
            temp.pop_back();

            // multiply
            temp.push_back('*');
            temp.push_back(num[index]);
            val = calculate(temp);
            helper(num, target, val, ans, temp, index + 1);
            temp.pop_back();
            temp.pop_back();
        }

        // minus
        temp.push_back('-');
        temp.push_back(num[index]);
        val = calculate(temp);
        helper(num, target, val, ans, temp, index + 1);
        temp.pop_back();
        temp.pop_back();

        // For not doing something
        temp.push_back(num[index]);
        val = calculate(temp);
        helper(num, target, val, ans, temp, index + 1);
        temp.pop_back();
    }
    vector<string> addOperators(string num, int target)
    {
        vector<string> ans;
        string temp = "";
        temp.push_back(num[0]);
        int val = num[0] - '0';
        helper(num, target, val, ans, temp, 1);
        return ans;
    }
};

// Here val is calculated only when index gets equal to size().
class Solution
{
public:
    int calculate(string s)
    {
        int len = s.length();
        if (len == 0)
            return 0;
        stack<int> stack;
        int currentNumber = 0;
        char operation = '+';
        for (int i = 0; i < len; i++)
        {
            char currentChar = s[i];
            if (isdigit(currentChar))
            {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!isdigit(currentChar) && !iswspace(currentChar) || i == len - 1)
            {
                if (operation == '-')
                {
                    stack.push(-currentNumber);
                }
                else if (operation == '+')
                {
                    stack.push(currentNumber);
                }
                else if (operation == '*')
                {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop * currentNumber);
                }
                else if (operation == '/')
                {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop / currentNumber);
                }
                operation = currentChar;
                currentNumber = 0;
            }
        }
        int result = 0;
        while (stack.size() != 0)
        {
            result += stack.top();
            stack.pop();
        }
        return result;
    }
    void helper(string num, int target, vector<string> &ans, string temp, int index)
    {
        if (index == num.size())
        {
            long long val = calculate(temp);
            if (target == val)
            {
                ans.push_back(temp);
            }
            return;
        }

        // plus
        temp.push_back('+');
        temp.push_back(num[index]);
        helper(num, target, ans, temp, index + 1);
        temp.pop_back();
        temp.pop_back();

        // multiply
        temp.push_back('*');
        temp.push_back(num[index]);
        helper(num, target, ans, temp, index + 1);
        temp.pop_back();
        temp.pop_back();

        // minus
        temp.push_back('-');
        temp.push_back(num[index]);
        helper(num, target, ans, temp, index + 1);
        temp.pop_back();
        temp.pop_back();

        // For not doing something
        temp.push_back(num[index]);
        helper(num, target, ans, temp, index + 1);
        temp.pop_back();
    }
    vector<string> addOperators(string num, int target)
    {
        vector<string> ans;
        string temp = "";
        temp.push_back(num[0]);
        int val = num[0] - '0';
        helper(num, target, ans, temp, 1);
        return ans;
    }
};

// This answer is also correct here the value is calculated on the go.
class Solution
{
public:
    vector<string> answer;
    string digits;
    long target;

    void recurse(int index, long previousOperand, long currentOperand, long value, vector<string> ops)
    {
        string nums = this->digits;

        // Done processing all the digits in num
        if (index == nums.length())
        {
            // If the final value == target expected AND
            // no operand is left unprocessed
            if (value == this->target && currentOperand == 0)
            {
                string ss;
                for (int i = 1; i < ops.size(); i++)
                {
                    ss += ops[i];
                }
                this->answer.push_back(ss);
            }
            return;
        }

        // Extending the current operand by one digit
        currentOperand = currentOperand * 10 + nums[index] - '0';
        string current_val_rep = to_string(currentOperand);

        // To avoid cases where we have 1 + 05 or 1 * 05 since 05 won't be a
        // valid operand. Hence this check
        if (currentOperand > 0)
        {
            // NO OP recursion
            recurse(index + 1, previousOperand, currentOperand, value, ops);
        }

        // ADDITION
        ops.push_back("+");
        ops.push_back(current_val_rep);
        recurse(index + 1, currentOperand, 0, value + currentOperand, ops);
        ops.pop_back();
        ops.pop_back();

        if (ops.size() > 0)
        {
            // SUBTRACTION
            ops.push_back("-");
            ops.push_back(current_val_rep);
            recurse(index + 1, -currentOperand, 0, value - currentOperand, ops);
            ops.pop_back();
            ops.pop_back();

            // MULTIPLICATION
            ops.push_back("*");
            ops.push_back(current_val_rep);
            recurse(index + 1, currentOperand * previousOperand, 0, value - previousOperand + (currentOperand * previousOperand), ops);
            ops.pop_back();
            ops.pop_back();
        }
    }

    vector<string> addOperators(string num, int target)
    {

        if (num.length() == 0)
        {
            return vector<string>();
        }

        this->target = target;
        this->digits = num;
        this->answer = vector<string>();
        this->recurse(0, 0, 0, 0, vector<string>());
        return this->answer;
    }
};

class Solution
{
public:
    vector<string> addOperators(string num, int target)
    {
        vector<string> ans;
        recursion(ans, num, target, "", 0, 0, 0);
        return ans;
    }

    void recursion(vector<string> &ans, const string &num, const int &target, string expression, int idx, int prevNum, long long curTotal)
    {
        int n = num.size();
        if (idx == n)
        {
            if (curTotal == target)
            {
                ans.push_back(expression);
            }
            return;
        }
        string curNumStr = "";
        long long curNum = 0;
        for (int i = idx; i < n; i++)
        {
            if (i > idx && num[idx] == '0')
                break;
            curNumStr += num[i];
            curNum = curNum * 10 + (num[i] - '0');
            // 2345
            if (idx == 0)
            {
                recursion(ans, num, target, expression + curNumStr, i + 1, curNum, curTotal + curNum);
            }
            else
            {
                recursion(ans, num, target, expression + "+" + curNumStr, i + 1, curNum, curTotal + curNum);
                recursion(ans, num, target, expression + "-" + curNumStr, i + 1, -curNum, curTotal - curNum);
                recursion(ans, num, target, expression + "*" + curNumStr, i + 1, prevNum * curNum, curTotal - prevNum + prevNum * curNum);
            }
        }
    }
};

int main()
{

    return 0;
}