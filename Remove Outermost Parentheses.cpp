#include <bits/stdc++.h>
using namespace std;

// In this approach the intution is to store the indexes of chars which we don't want in the answer. And iterating second time for getting the answer.
// The indexes we don't want or the indexes we are storing are those parenthesis whose removal from the stack will make stack empty during the iteration (The outer ones).
// So top and bottom are the top of the stack and bottom of the stack. So the logic is that before the stack get's empty I am storing the bottom and the potential top. So at last after if statements I am checking if the stack is empty after the poping. If yes it means these are those indexes whose removal will make stack empty so I put it into the map.

class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        int top = 0, bottom = 0;
        stack<char> st;
        stack<int> stnum;
        map<int,int>mp;
        string ans = "";
        for(int i = 0; i < n ; i++){
            if(st.empty()){
                bottom = i;
            }
            if(st.empty() || s[i] == '('){
                st.push(s[i]);
                stnum.push(i);
            }
            else if(s[i] == ')' && st.top() == '('){
                top = i;
                st.pop();
                stnum.pop();
            }
            
            if(st.empty()){
                mp[top]++;
                mp[bottom]++; 
            }
        }
        for(int i = 0; i < n ; i++){ // Iterating and not including the mapped indexes.
            if(!mp[i]){
                ans += s[i];
            }
        }
        return ans;
    }
};

// In this approach rather than storing the indexes of chars which I don't want to include I am trying to get the elements that I want directly and add it to the answer.
// Logic is simple as above just their is small tweaking for getting the desired chars to add in ans.
class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        stack<char> st;
        string ans = "";
        for(int i = 0; i < n ; i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }

            if(s[i] == '('){
                st.push(s[i]);
                ans += s[i];
            }
            else if(s[i] == ')' && st.top() == '('){
                st.pop();
                if(!st.empty()){
                    ans += s[i];
                }
            }
        }
        return ans;
    }
};

int main(){
    

    return 0;
}