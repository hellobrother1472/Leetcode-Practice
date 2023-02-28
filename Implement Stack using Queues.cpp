#include <bits/stdc++.h>
using namespace std;

// Using two queues push - O(1), pop() - O(n)
class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    // Another way to implement pop is to transfer the values from q1 to q2 and after the operation is done swap the values of two queues
    int pop() {
        int store;
        if(q1.size() == 0){
            while(q2.size()>1){
                q1.push(q2.front());
                q2.pop();
            }
            store = q2.front();
            q2.pop();
        }
        else if(q1.size() == 1){
            store = q1.front();
            q1.pop();
        }
        else{
            while(q1.size()>1){
                q2.push(q1.front());
                q1.pop();
            }
            store = q1.front();
            q1.pop();
        }
        return store;
    }

    
    int top() {
        if(q1.empty()) return q2.back();
        return q1.back();
    }
    
    bool empty() {
        if(q1.empty() && q2.empty()) return true;
        return false;
    }
};

// Using One queue push - O(n), pop() - O(1)
class MyStack {
public:
    queue<int>q1;
    MyStack() {

    }
    
    void push(int x) {
        if(q1.empty()) q1.push(x);
        else{
            // taking inserted element to start
            q1.push(x);
            int index = q1.size();
            while(index > 1){
                int val = q1.front();
                q1.pop();
                q1.push(val);
                index--;
            }
        }
    }
    
    int pop() {
        int store = q1.front();
        q1.pop();
        return store;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if(q1.empty()) return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main(){

    return 0;
}