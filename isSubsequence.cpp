#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0){
            return true;
        }
        int i = 0, j = 0;
        while(j< t.size()){
            if(s[i] == t[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }

        if(i>= s.size()){
            return true;
        }
        

        return false;
    }
};

int main(){
    string a = "hello";
    cout << a.size();

    return 0;
}