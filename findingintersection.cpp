#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        int j = 0;
        vector<int> intersection;

        for (int i = 0; i < nums1.size(); i++)
        {
            if (nums1[i] != nums2[j])
            {
                j++;
                i--;
            }
            else
            {
                intersection.push_back(nums1[i]);

                nums2[j] = -1;
                j = 0;
            }

            if (j == nums2.size())
            {
                j = 0;
                i++;
            }
        }
        return intersection;
    }
};

class Solution2 {   // Another approach to solve the problem
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
        
        map<int,int> mp;
        
        for(int i = 0 ; i < nums1.size() ; i++ ){
            mp[nums1[i]]++;
        }
        
        vector<int> ans;
        
        for(int i = 0 ; i < nums2.size() ; i++ ){
            
            if( mp[nums2[i]] != 0 ){
                mp[nums2[i]]--;
                ans.push_back(nums2[i]);
            }
        }

        return ans;
    
    }
};

// If we want non repetetive numbers in answer

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
        
        map<int,int> mp;
        // map<int,int>
        for(int i = 0 ; i < nums1.size() ; i++ ){
            mp[nums1[i]]++;
        }
        
        vector<int> ans;
        
        for(int i = 0 ; i < nums2.size() ; i++ ){
            
            if( mp[nums2[i]] != 0 ){
                mp[nums2[i]]=0; // If we entered once then we do not repeat it.
                ans.push_back(nums2[i]);
            }
        }

        return ans;
    
    }
};


int main()
{

    return 0;
}