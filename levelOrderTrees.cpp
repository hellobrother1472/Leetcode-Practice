#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    void solve(vector<vector<int>>&ans,int level, TreeNode *root){
        if(root == NULL){
            return;
        }

        if(ans.size()<level){
            vector<int> ds;
            ds.push_back(root->val);
            ans.push_back(ds);
        }
        else{
            if(count(ans[level].begin(), ans[level].end(), root->val)){
                return;
            }
            else{
                ans[level].push_back(root->val);
            }
        }

        solve(ans,level+1,root->left);
        solve(ans,level+1,root->right);
        
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        solve(ans,0,root);
        return ans;
    }
};

int main()
{

    return 0;
}