#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &a, vector<int> &b)
    {
        int j = 0;
        vector<int> intersection;

        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[j])
            {
                j++;
                i--;
            }
            else
            {
                intersection.push_back(a[i]);

                b[j] = -1;
                j = 0;
            }

            if (j == b.size())
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

int main()
{

    return 0;
}