#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>st;
        for(int i  = 0 ; i < asteroids.size(); i++){
            if(st.empty() || asteroids[i] >=0 || st.top() * asteroids[i] > 0){
                st.push(asteroids[i]);
                continue;
            }
            
            while(!st.empty() && st.top() * asteroids[i] < 0 && st.top()+asteroids[i] < 0){
                st.pop();
            }
            if(st.empty() || st.top() < 0){ 
                st.push(asteroids[i]);
                continue;
            }
            if(st.top()+asteroids[i] == 0){
                st.pop();
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    
    return 0;
}