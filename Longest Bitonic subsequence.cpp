#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=y4vN0WNdrlg&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=47
class Solution{
	public:
	int LongestBitonicSequence(vector<int>arr)
	{
	    // code here
	    int n = arr.size();
	    vector<int> dp1(n,1);
        vector<int> dp2(n,1);
        
        for(int i=0; i<=n-1; i++){
            for(int prev_index = 0; prev_index <=i-1; prev_index ++){
                
                if(arr[prev_index]<arr[i]){
                    dp1[i] = max(dp1[i], 1 + dp1[prev_index]);
                }
            }
        }
        
        // reverse the direction of nested loops
        for(int i=n-1; i>=0; i--){
            for(int prev_index = n-1; prev_index >i; prev_index --){
                
                if(arr[prev_index]<arr[i]){
                    dp2[i] = max(dp2[i], 1 + dp2[prev_index]);
                }
            }
        }
        
        int maxi = -1;
        
        for(int i=0; i<n; i++){
            maxi = max(maxi, dp1[i] + dp2[i] - 1);
        }
        
        return maxi;
	}
};

int main(){

    return 0;
}