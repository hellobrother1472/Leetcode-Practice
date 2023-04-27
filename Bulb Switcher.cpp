#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        vector<bool>bulbs(n,false);
        int i = 1;
        while(i <= n){
            for(int j = i ; j <= n; j += i){
                bulbs[j-1] = !bulbs[j-1];
            }
            i++;
        }
        int ans = 0;
        for(int j = 0 ; j < n; j++){
            if(bulbs[j]) ans++;
        }
        return ans;
    }
};

class Solution {
public:
    int bulbSwitch(int n) {
        vector<bool>bulbs(n,false);
        int i = 1;
        int ans = 0;
        while(i <= n){
            for(int j = i ; j <= n; j += i){
                bulbs[j-1] = !bulbs[j-1];
                if(bulbs[j-1]) ans++;
                else ans--;
            }
            i++;
        }
        
        return ans;
    }
};

class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};

int main(){
    

    return 0;
}