#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MyQueue
{
     stack<int> st1, st2;

public:
     MyQueue()
     {
     }
     void push(int x)
     {
          st1.push(x);
     }
     int pop()
     {
          int x;
          if (!st2.empty())
          {
               int x = st2.top();
               st2.pop();
               return x;
          }
          else
          {
               while (!st1.empty())
               {
                    x = st1.top();
                    st1.pop();
                    st2.push(x);
               }
               x = st2.top();
               st2.pop();
               return x;
          }
     }
     int peek()
     {
          int x;
          if (!st2.empty())
          {
               x = st2.top();
               return x;
          }
          else
          {
               while (!st1.empty())
               {
                    x = st1.top();
                    st1.pop();
                    st2.push(x);
               }
               x = st2.top();
               return x;
          }
     }
     bool empty()
     {
          return (st1.size() + st2.size()) == 0;
     }
};

int main()
{

    return 0;
}