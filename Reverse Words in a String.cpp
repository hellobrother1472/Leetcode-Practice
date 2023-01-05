#include <bits/stdc++.h>
using namespace std;

// Firstly I am making the vector of the strings from the given s. Then I am reversing the vector and then I am joining it again space seperated.
// Second step of reversing the vector can be avoided as we can start iteration form end till front.
class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> st;
        string str = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                if (str != "")
                    st.push_back(str);
                str = "";
            }
            else
            {
                str += s[i];
            }
            if (i == s.length() - 1 && str != "")
                st.push_back(str);
        }
        int a = 0, b = st.size() - 1;
        while (a <= b)
        {
            string temp = st[a];
            st[a] = st[b];
            st[b] = temp;
            a++;
            b--;
        }
        s = "";
        for (int i = 0; i < st.size(); i++)
        {
            s += st[i];
            if (i != st.size() - 1)
                s += " ";
        }
        return s;
    }
};

int main()
{
    return 0;
}