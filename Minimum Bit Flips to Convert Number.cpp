#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        // xor both the bits and count the set bits
        if(start == goal) return 0;
        int ans = 0;
        int a = start ^ goal;
        while(a != 0){
            if(a & 1 != 0) ans++;
            a = a >> 1;
        }
        return ans;
    }
};

int main(){

    return 0;
}