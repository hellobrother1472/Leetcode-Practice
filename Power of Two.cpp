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

// Using bit manipulation
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0 || n == -1) return false;
        if(n > 0){
            return (n & n-1) == 0;
        }
        return (n & n+1) == 0;
    }
};

int main(){

    return 0;
}