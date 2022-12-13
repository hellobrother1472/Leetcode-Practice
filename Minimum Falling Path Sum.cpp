#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int f(int i,int j,int n,int m,vector<vector<int>>& a)
    {
        if(j<0 || j>m-1)
            return 1e9;
        
        if(i==0)
            return a[i][j];
        
        int up = a[i][j] + f(i-1,j,n,m,a);
        
        int ld = a[i][j] + f(i-1,j-1,n,m,a);
        
        int rd = a[i][j] + f(i-1,j+1,n,m,a);
        
        
        return min(up,min(ld,rd));
        
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n=matrix.size();
        
        int m=matrix[0].size();
        for(int j=0;j<m;j++)
        {
            ans=min(ans,f(n-1,j,n,m,matrix));
        }
        return ans;
    }
};

int main(){
    

    return 0;
}