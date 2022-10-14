#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        // Meathod 1
        //    vector<int> ans;

        //    for (int i = 0; i < ans.size(); i++)
        //    {
        //     for (int j = i; j < ans.size(); j++)
        //     {
        //         if(nums[i] + nums[j] == target){
        //             ans.push_back(nums[i]);
        //             ans.push_back(nums[j]);
        //         }
        //         else{
        //             continue;
        //         }
        //     }

        //    }

        //    return ans;

        // Meathod 2 (Two Pointers Meathod)
        vector<int> ans;

    }
};

// Using two pointer
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res,store;
    	store = nums;

    	sort(store.begin(), store.end());

    	int left=0,right=nums.size()-1;
    	int n1,n2;

    	while(left<right){
        	if(store[left]+store[right]==target){

            	n1 = store[left];
            	n2 = store[right];

            	break;

        	}
        	else if(store[left]+store[right]>target)
            	    right--;
        	else
            	    left++;
    	}

        // Getting the index of the founded elements
    	for(int i=0;i<nums.size();++i){

        	if(nums[i]==n1)
            	    res.emplace_back(i);
        	else if(nums[i]==n2)
            	    res.emplace_back(i);
    	}

    	    return res;
    }
    
};

void display(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    vector<int> a = {2, 7, 11, 15};
    class Solution b;
    display(b.twoSum(a, 9));
    return 0;
}