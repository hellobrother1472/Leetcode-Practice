#include <bits/stdc++.h>
using namespace std;

// Using the concept of finding the greatest element on left, and after finding that we are subtracting the current index with that index so we got the number of elements in between

class StockSpanner {
public:
    stack<pair<int,int>>st;
    int count = 0;
    StockSpanner() {
        
    }    
    int next(int price) {
        cout << price << " : ";
        count++;
        cout << count << endl;
        pair<int,int>p;
        p.second = count;
        p.first = price;
        
        while(!st.empty() && st.top().first <= price) st.pop();
        if(st.empty()){
            st.push(p);
            return count;
        }
        int ans = count - st.top().second;
        st.push(p);
        return ans;       
    }
};

int main(){

    return 0;
}