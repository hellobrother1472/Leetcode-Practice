// hello
#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        if(s.length()==0){
            return true;
        }
        if(s.length()==1){
            return false;
        }
        stack<char> stk;
        stk.push(1);
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i] == stk.top() + 1 || s[i] == stk.top()+2 ){
                stk.pop();
            } else{
                stk.push(s[i]);
            }
        }
        
        if(stk.top() == NULL){
            return true;
        } else{
            return false;
        }
    }
};

int main()
{
    stack<int> st;
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(int("("));
    // while (!st.empty())
    // {
    //     cout << ' ' << st.top();
    //     st.pop();
    // }

    string c = "((((()))))";
    cout << int(c[5]);

    return 0;
}

// class Solution
// {
// public:
//     bool isValid(string s)
//     {
//         stack<int> st;
//         st.push(1);
//         for (int i = 0; i < s.size(); i++)
//         {
//             if (int(s[i]) == st.top() + 1 || int(s[i]) == st.top() + 2 )
//             {
//                 st.pop();
//             }
//             else
//             {
//                 st.push(int(s[i]));
//             }
//         }
//         if (st.top() == 1 || st.empty())
//         {
//             return true;
//         }
//         return false;
//     }
// };