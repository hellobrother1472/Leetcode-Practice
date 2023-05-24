#include <bits/stdc++.h>
using namespace std;

// Just doing the spiral matrix 1 iteration and using last as the count and filling the value.

class Solution {
private:
    int helper(vector<vector<int>>&ans, int starti, int startj,int n,int m,int last){
        int i = starti, j = startj;
        while(j <= m){
            ans[i][j] = last + 1;
            last++;
            j++;
        }
        i++;
        j--;
        if(i == n+1) return last;

        while(i <= n){
            ans[i][j] = last + 1;
            last++;
            i++;
        }
        j--;
        i--;
        if(j < startj) return last;

        while(j >= startj){
            ans[i][j] = last + 1;
            last++;
            j--;
        }
        j++;
        i--;

        while( i > starti){
            ans[i][j] = last + 1;
            last++;
            i--;
        }
        return last;
    }
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        int starti = 0, startj = 0, a = n-1,m = n-1,last = 0;
        while(starti <= a && startj <= m){
            last = helper(ans,starti,startj,a,m,last);
            starti++;
            startj++;
            a--;
            m--;
        }
        return ans;
    }
};

int main(){

    return 0;
}