#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeFrontZeros(string str)
    {
        int n = str.length();
        int index = -1;
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            if (str[i] != '0' && str[i] != '-')
            {
                break;
            }
            else
            {
                index = i;
            }
        }
        for (int i = index + 1; i < n; i++)
        {
            ans += str[i];
        }
        return ans;
    }
    string removeBackElements(string str)
    {
        int n = str.length();
        int index = -100;
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '.')
            {
                index = i;
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i < index + 3)
            {
                ans += str[i];
            }
            else
            {
                break;
            }
        }
        if (index = -100)
            return str;
        return ans;
    }
    int myAtoi(string s)
    {
        int n = s.length();
        if (n == 0)
        {
            return 0;
        }
        bool zeroFlag = false;
        bool operationFlag = false;
        bool numFlag = false;
        string ans = "";
        string temp = "";
        for (int i = 0; i < n; i++)
        {
            if ((s[i] == '-' || s[i] == '+') && !operationFlag)
            {
                if (temp.length() != 0 && i != 0)
                {
                    ans = temp;
                    break;
                }

                if (48 <= s[i + 1] && s[i] <= 57)
                    temp += s[i];
                operationFlag = true;
            }
            else if (48 <= s[i] && s[i] <= 57 || (s[i] == '.' && i != 0))
            {
                numFlag = true;
                temp += s[i];
            }
            else
            {
                if (!numFlag && s[i] != ' ')
                    return 0;
                if (numFlag && s[i] != ' ')
                {
                    ans = temp;
                    break;
                }
            }
            if (i == n - 1 || (temp.length() != 0 && s[i] == ' '))
            {
                ans = temp;
                break;
            }
        }

        if (ans.length() > 12)
        {
            string sign = "";
            if (ans[0] == '-' || ans[0] == '+')
                sign += ans[0];
            ans = sign + removeFrontZeros(ans);
        }
        if (ans.length() > 12)
            ans = removeBackElements(ans);
        if (ans.length() > 12)
        {
            if (ans[0] == '-')
                return INT_MIN;
            return INT_MAX;
        }
        if (ans == "")
            return 0;
        long long realAns = stoll(ans);
        if (realAns < INT_MIN)
            return INT_MIN;
        if (realAns > INT_MAX)
            return INT_MAX;
        int ln = stoi(ans);
        return ln;
    }
};

// Reccursive approach
// Approach is similar to above just make a string according to conditions and then remove initial zeros and then analyse and give answer.
class Solution {
public:
    string ans = "";
    bool num = false;
    string removeInitZero(string a){
        string sol = "";
        bool number = false;
        for(int i = 0 ; i<a.length() ; i++){
            if(a[i] == '+' || a[i] == '-'){ sol += a[i] ;continue;}
            if(a[i] >=49) number = true;
            if(number) sol += a[i];
        }
        return sol;
    }
    void getStr(string s, int i){
        if( 58<= s[i] || (s[i]<= 47 && s[i] != 45 && s[i] != 43 && s[i] != ' ') || i>=s.length()){
            return;
        }
        if(num && (s[i] == 45 || s[i] == 43 || s[i] == ' ')){
            return;
        }

        if(s[i] == ' ') {
            getStr(s,i+1);
        }
        else{
            ans += s[i];
            num = true;
            getStr(s,i+1);
        }
    }
    int myAtoi(string s) {
        if(s.length() == 0) return 0;
        getStr(s,0);
        ans = removeInitZero(ans);
        if(ans.length() == 0 || ans[ans.length()-1] == '-' || ans[ans.length()-1] == '+') return 0;
        if(ans.length()>= 12){
            if(ans[0] == '-') return INT_MIN;
            return INT_MAX;
        }
        long long longAns;
        if(ans.length() >= 9){
            longAns = stoll(ans);
            if(longAns<= INT_MIN) return INT_MIN;
            if(longAns>=INT_MAX) return INT_MAX;
        }
        int realAns = stoi(ans);
        return realAns;
        return 0;
    }
};

int main()
{
    return 0;
}