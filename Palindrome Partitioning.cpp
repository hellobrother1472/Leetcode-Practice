#include <bits/stdc++.h>
using namespace std;

// https://drive.google.com/file/d/1H7dIVsMM2_4uDo4FKqVAO04CLXvci1fR/view?usp=sharing - Link of picture of reccursion tree
// Let's take the example of "aab".
// The approach is at level 1 "" can have values "a", "aa", "aab" . 
// At level 2 for "a" it can have value "a", "ab", for "aa" -> "b", for "aab"-> X.
// It goes like this and check values.
// Starting with an empty string, I am making a newTemp which is empty initially and is a local variable and which is empty in every reccursion
// Now as for loop starts it makes newTemp = "a" (Level 1) then it calls reccursion for index+1. Now I check for palindrome so it is palindrome so I add it to ds and continue.
// Now newTemp = "a"(Level 2) and it calls reccursion again and again check palindrome at level 3.
// This continues and that's how temp is helping in getting the fresh string which start from the given index if we get previous one as a plindrome other wise it is returning.
class Solution {
public:
    bool checkPalindrome(string temp){ // check if the given string is palindrom or not
        if(temp.size() == 1 || temp.size() == 0) return true;
        int i = 0, j = temp.size()-1;
        while(j > i){
            if(temp[i] != temp[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void helper(string s,int index,vector<vector<string>>&ans, vector<string>&ds, string temp){
        bool palindrome = checkPalindrome(temp);
        if(!palindrome){ return;} // IF not palindrome then return
        else{
            if(temp != ""){
                ds.push_back(temp); // if palindrome other then "" then add to ds
            }
        }
        if(index >= s.size()){ // base condition
            ans.push_back(ds);
            return;
        }
        string newTemp = ""; // newTemp is "" for every reccursion understand it by tracing and looking the image
        for(int i = index; i < s.size() ; i++){
            newTemp.push_back(s[i]); // add the present i value 
            helper(s,i+1,ans,ds,newTemp); // start reccursion for i+1 value not index+1 because we want i+1 not index+1.
            if(ds.size() != 0 && ds[ds.size()-1] == newTemp) ds.pop_back(); // remove ds's last element which we added so that we can get fresh ds
        } 
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>ds;
        string temp = "";
        helper(s,0,ans,ds,temp);
        return ans;
    }
};

int main(){

    return 0;
}