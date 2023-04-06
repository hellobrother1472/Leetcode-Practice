#include <bits/stdc++.h>
using namespace std;

// Question is a version of minimum difference between two numbers just here we have to maintain a window size of m.
// As we sort the difference between the minimum number and higher number is the expected answer so we compare this in whole array.

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(),a.end());
        int i = 0, j = m-1;
        long long ans = INT_MAX;
        while(j<n){
            if(ans > a[j] - a[i]) ans = a[j] - a[i];
            j++;
            i++;
        }
        return ans;
    }   
};

int main(){

    return 0;
}