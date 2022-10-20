#include <bits/stdc++.h>

using namespace std;

// logic is to count on the basis of consicutiveness, if I get the element which is not consicutive I store the value and reset count and again follow the same process. This approach follows o(n)+O(nlogn) .
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums.size();
        } 
        sort(nums.begin(),nums.end());
        int finalCount = 1;
        int count = 1;
        for(int i = 1 ; i < nums.size(); i++){
            if(nums[i] == nums[i-1]+1){
                count++;
                if(count > finalCount){
                    finalCount = count;
                }
            }
            else if(nums[i] == nums[i-1]){
                continue;
            }
            else{
                count = 1;
            }
            
        }
        return finalCount;
    }
};

// O(n) solution. Storing in hashmap and if the element does'nt have the previous value so while it has next consicutive value present count it and after the while loop compare and update ans.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums.size();
        } 
        unordered_set<int>hashmap;
        for (int i = 0; i < nums.size(); i++)
        {
            hashmap.insert(nums[i]);
        }
        
        int ans = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if(!hashmap.count(nums[i]-1)){
                int currNum = nums[i];
                int currCount = 1;
                while(hashmap.count(currNum+1)){
                    currNum +=1;
                    currCount +=1;
                } 
                ans = max(currCount,ans);
            }
        }
        
        return ans;
    }
};

int main(){
    

    return 0;
}