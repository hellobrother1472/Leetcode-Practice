#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> minPartition(int N)
    {
        int arr[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        vector<int>ans;
        int i = 9;
        while(N>0){
            while(N >= arr[i]){
                N -= arr[i];
                ans.push_back(arr[i]);
            }
            i--;
        }
        return ans;
    }
};

int main(){

    return 0;
}