#include <bits/stdc++.h>
using namespace std;

// The string which is created by pressing the number is form the alphabets related to it, so make an vector called alphabets to use it.
// Now the approach is the alpabets in the output string should be in order of digits and we have to try every digit at every place so we are doing so by using for loop , reccursion and backtracking.

class Solution {
public:

    void solve(vector<string> alphabets, string output, vector<string> & ans, int index, string digits){
        if(output.size() == digits.size()) {
            ans.push_back(output);
            return;
        }
        if(index >= digits.size()) return;
        int num = digits[index] - 48;
        if(alphabets[num].length() == 0) solve(alphabets,output,ans,index+1,digits); // This is not necessary without it code is still working
        for(int i = 0; i < alphabets[num].length() ; i++){
            output.push_back(alphabets[num][i]);
            solve(alphabets,output,ans,index+1,digits);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0) return ans; 
        vector<string> alphabets = {"", "","abc", "def", "ghi","jkl", "mno","pqrs","tuv", "wxyz"};        
        string output;
        solve(alphabets,output,ans,0,digits);
        return ans;
    }
};


int main(){

    return 0;
}