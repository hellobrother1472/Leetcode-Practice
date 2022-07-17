#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
public:
     stack<int> st1;
     stack<int> st2;
     MyQueue()
     {
     }

     void push(int x)
     {
          st1.push(x);
     }

     int pop()
     {
          int store;
          if (st2.top() != NULL)
          {
               store = st2.top();
               st2.pop();
          }
          else
          {
               while (st1.top() != NULL)
               {
                    st2.push(st1.top());
                    st1.pop();
               }
               store = st2.top();
               st2.pop();
          }
          return store;
     }

     int peek()
     {
          int store;
          if (st2.top() != NULL)
          {
               store = st2.top();
          }
          else
          {
               while (st1.top() != NULL)
               {
                    st2.push(st1.top());
                    st1.pop();
               }
               store = st2.top();
               st2.pop();
          }
          return store;
     }

     bool empty()
     {
          if (st1.top() == NULL && st2.top() == NULL)
          {
               return false;
          }
          else
          {
               return true;
          }
     }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{

     return 0;
}