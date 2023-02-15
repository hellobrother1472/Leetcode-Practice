#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    stack<int> ansSt;
    void Reverse(stack<int> &St)
    {
        if (St.empty())
        {
            St = ansSt;
            return;
        }
        ansSt.push(St.top());
        St.pop();
        Reverse(St);
    }
};

void Reverse(stack<int> &St)
{

    if (!St.empty())
    {
        return;
    }
    int a = St.top();
    St.pop();
    Reverse(St);
    St.push(a);
}

int main()
{

    return 0;
}