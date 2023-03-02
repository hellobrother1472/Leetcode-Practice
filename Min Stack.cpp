#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    int min = INT_MAX;
    stack<pair<int,int>>st;
    pair<int,int>p;
    MinStack() {
        
    }
    
    void push(int val) {
        p.first = val;
        if(st.empty()){            
            p.second = val;
        }
        else{
            if(val < st.top().second) p.second = val;
            else p.second = st.top().second;
        }
        st.push(p);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

// Using less space avoiding pair
class MinStack {
public:
    long long int min = INT_MAX;
    stack<long long int>st;
    MinStack() {
        
    }

    void push(int val) {
        if(st.empty()){
            st.push(val);
            min=val;
        }
        else{
            if(val>=min)
               {st.push(val);}
            else if(val< min){
                st.push(2LL*val-min);
                min=val;
            }
        }
    }
    
    void pop() {
        if(st.top()<min){
            min = 2*min-st.top();
            st.pop();
        }
        else st.pop();
    }
    
    int top() {
        if(st.top()<min) return min;
        else return st.top();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){

    return 0;
}