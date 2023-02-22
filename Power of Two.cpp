#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1) return true;
        if(n%2 != 0 || n == 0) return false;
        while(n != 0){
            n = n >> 1;
            if(n%2 != 0 && n != 1) return false; 
        }
        return true;
    }
};

int main(){

    return 0;
}