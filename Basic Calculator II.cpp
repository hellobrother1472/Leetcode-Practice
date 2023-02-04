#include <bits/stdc++.h>
using namespace std;

// Seperating the number and sign in stack.
// Then reversing the stack so that we can get correct order
// Then perform divide and multiplication first and then addition and substraction.
class Solution
{
public:
    int calculate(string s)
    {
        stack<string> st1;
        stack<string> st2;
        string temp = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
                continue;
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                st1.push(temp);
                temp = "";
                temp.push_back(s[i]);
                st1.push(temp);
                temp = "";
            }
            else
            {
                temp.push_back(s[i]);
            }
        }
        st1.push(temp);
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        // for multiply and divide
        while (!st2.empty())
        {
            if (st2.top() != "*" && st2.top() != "/")
            {
                st1.push(st2.top());
                st2.pop();
            }
            else
            {
                int num1 = stoi(st1.top());
                st1.pop();
                if (st2.top() == "/")
                {
                    st2.pop();
                    int num2 = stoi(st2.top());
                    st2.pop();
                    int newNum = num1 / num2;
                    string newS = to_string(newNum);
                    st1.push(newS);
                }
                else if (st2.top() == "*")
                {
                    st2.pop();
                    int num2 = stoi(st2.top());
                    st2.pop();
                    int newNum = num1 * num2;
                    string newS = to_string(newNum);
                    st1.push(newS);
                }
            }
        }
        // Resetting
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        // For addition and substraction
        while (!st2.empty())
        {
            if (st2.top() != "+" && st2.top() != "-")
            {
                st1.push(st2.top());
                st2.pop();
            }
            else
            {
                int num1 = stoi(st1.top());
                st1.pop();
                if (st2.top() == "-")
                {
                    st2.pop();
                    int num2 = stoi(st2.top());
                    st2.pop();
                    int newNum = num1 - num2;
                    string newS = to_string(newNum);
                    st1.push(newS);
                }
                else if (st2.top() == "+")
                {
                    st2.pop();
                    int num2 = stoi(st2.top());
                    st2.pop();
                    int newNum = num1 + num2;
                    string newS = to_string(newNum);
                    st1.push(newS);
                }
            }
        }
        int ans = stoi(st1.top());
        return ans;
    }
};

// Collecting the current number, then pushing it in stack such that plus and minus are pushed by putting it's sign respectively.
// For the multiply and divide stack.top() is taken out and calculation is done and result is then stored in stack.
// So at last the simple addition is done.
int calculate(string s)
{
    int len = s.length();
    if (len == 0)
        return 0;
    stack<int> stack;
    int currentNumber = 0;
    char operation = '+'; // because the first number is always positive
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

// Above concept without using stack
int calculate(string s)
{
    int ans = 0;
    int prevNum = 0;
    int currNum = 0;
    char op = '+';

    for (int i = 0; i < s.length(); ++i)
    {
        const char c = s[i];
        if (isdigit(c))
            currNum = currNum * 10 + (c - '0');
        if (!isdigit(c) && !isspace(c) || i == s.length() - 1)
        {
            if (op == '+' || op == '-')
            {
                ans += prevNum;
                prevNum = (op == '+') ? currNum : -currNum;
            }
            else if (op == '*')
            {
                prevNum *= currNum;
            }
            else if (op == '/')
            {
                prevNum /= currNum;
            }
            op = c;
            currNum = 0;
        }
    }

    return ans + prevNum;
}

// Collecting the current number, then pushing it in stack such that plus and minus are pushed by putting it's sign respectively.
// For the multiply and divide stack.top() is taken out and calculation is done and result is then stored in stack.
// So at last the simple addition is done.
int calculate(string s)
{
    int len = s.length();
    if (len == 0)
        return 0;
    stack<int> stack;
    int currentNumber = 0;
    char operation = '+'; // because the first number is always positive
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

int main()
{

    return 0;
}