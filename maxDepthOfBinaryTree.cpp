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

class Solution1 // Using the parameter type reccursion
{
public:
    void helper(vector<int>&arr, int level, TreeNode*root){
        if(root == NULL){
            return;
        }
        
        arr.push_back(level);
        helper(arr,level+1,root->left);
        helper(arr,level+1,root->right);
    }

    int maxDepth(TreeNode *root)
    {
        vector<int>arr;
        
        helper(arr,1,root);
        sort(arr.begin(),arr.end());
        return arr[arr.size()-1];
    }
};

class Solution2
{
public:
    int maxDepth(TreeNode *root)
    {
        if(root == NULL){
            return 0;
        }
        return max(maxDepth(root->left),maxDepth(root->right)) +1 ;
    }
};



int main()
{

    return 0;
}