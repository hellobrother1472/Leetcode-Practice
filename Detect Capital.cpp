#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length() == 1){
            return true;
        }
        bool flag1 = false, flag2 = false, flag3 = false;
        if(word[0]>=65 && word[0]<=90) {
            flag1 = true;
            flag3 = true;
        }
        else{
            flag2 = true;
        }
        if(flag3 && word[1]>=65 && word[1]<=90){
            flag3 = false;
        }
        cout << flag3;
        for(int i = 1; i<word.length(); i++){
            if(flag3 || flag2){
                if(word[i]>=65 && word[i]<=90){
                    return false;
                }
            }
            else if(flag1 && (word[i]>90 || word[i] < 65)){
                return false;
            }
            
        }
        return true;
    }
};

int main(){

    return 0;
}