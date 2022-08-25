#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:

    void rfunc(vector<int> &arr, vector<int>&ans, int n ,int i, int sum){
        if(i >= n){
            ans.push_back(sum);
            return;
        }
        sum += arr[i];
        rfunc(arr,ans,n,i+1,sum);
        sum -= arr[i];
        rfunc(arr,ans,n,i+1,sum);

    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        rfunc(arr,ans,N,0,0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    

    return 0;
}