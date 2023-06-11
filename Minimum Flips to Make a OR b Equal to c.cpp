#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void decToBinary(int n,vector<int>&ans)
    {
        // Size of an integer is assumed to be 32 bits
        for (int i = 31; i >= 0; i--) {
            int k = n >> i;
            if (k & 1)
                ans[i] = 1;
            else
                ans[i] = 0;
        }
    }
public:
    int minFlips(int a, int b, int c) {
        vector<int>aBits(32,0);
        vector<int>bBits(32,0);
        vector<int>cBits(32,0);
        decToBinary(a,aBits);
        decToBinary(b,bBits);
        decToBinary(c,cBits);
        reverse(aBits.begin(),aBits.end());
        reverse(bBits.begin(),bBits.end());
        reverse(cBits.begin(),cBits.end());
        int count = 0;
        for(int i = 31; i >= 0; i--){
            int req = cBits[i];
            int aBit = aBits[i];
            int bBit = bBits[i];
            if((aBit | bBit) != req){
                if(req == 1) count++;
                else if(req == 0){
                    if(aBit == 1 && bBit == 1) count += 2;
                    else count++;
                }
            }
        }
        return count;
    }
};

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        for(int i = 31; i >= 0; i--){
            int req = c >> i;
            if (req & 1) req = 1;
            else req = 0;

            int aBit = a >> i;
            if (aBit & 1) aBit = 1;
            else aBit = 0;

            int bBit = b >> i;
            if (bBit & 1) bBit = 1;
            else bBit = 0;
            
            if((aBit | bBit) != req){
                if(req == 1) count++;
                else if(req == 0){
                    if(aBit == 1 && bBit == 1) count += 2;
                    else count++;
                }
            }
        }
        return count;
    }
};

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int answer = 0;
        while (a != 0 | b != 0 | c != 0) {
            if ((c & 1) == 1) {
                if ((a & 1) == 0 && (b & 1) == 0) {
                    answer++;
                }
            } else {
                answer += (a & 1) + (b & 1);
            }
            
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        
        return answer;
    }
};

int main(){

    return 0;
}