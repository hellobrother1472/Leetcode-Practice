#include <bits/stdc++.h>
using namespace std;

// Make two stacks one for storing open brackets index and one for storing index of star.
// If '(' then push in open, if '*' push in star and if ')' comes then if their is any open bracket present to balance we balance it, if not then we balance it with the star if it is present.
// But after all this thier is some condition where thier is some open brackets left in stack, to tackle then we check that is thier any star present at some index greater than index of open, to check that we check that the further most star which is star.top() with the index of closest open which is open.top() if open.top() > star.top() it means it can be balanced
// so continuing this we run the while loop and at last we check if now the stack is empty or not if not return false else true.

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open,star;
        for(int i = 0 ; i < s.size();i++){
            if(s[i] == '(') open.push(i);
            else if (s[i] == '*') star.push(i);
            else{
                if(!open.empty()) open.pop();
                else if(!star.empty()) star.pop();
                else if(star.empty() && open.empty()) return false;
            }
        }
        while(!open.empty() && !star.empty()){
            if(open.top() > star.top()) return false;
            open.pop();
            star.pop();
        }
        return open.empty(); // return if open is empty or not
    }
};


int main(){

    return 0;
}