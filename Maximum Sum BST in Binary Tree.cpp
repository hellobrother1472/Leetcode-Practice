#include <iostream>
#include <vector>
#include <bits/stdc++.h>

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

// First brutforce approach is to validateBST at every node after getting the correct bst subtree apply operation on it to find the sum and compare. (This meathod takes order of N2)

// This is second approach in which we are taking values (leftMax,RightMin,maxSum) so that we can validate and store the values. The concept to validate BST is the max number of left should always be greater than the root and min number of right should always be greater than root.
class NodesValue
{
public:
    int maxSum, leftMax, rightMin;
    NodesValue(int maxSum, int leftMax, int rightMin)
    {
        this->maxSum = maxSum;
        this->leftMax = leftMax;
        this->rightMin = rightMin;
    }
};

class Solution
{
public:
    int sum = 0;
    NodesValue solve(TreeNode*root){
        if(root==NULL){
            return NodesValue(0,INT_MIN,INT_MAX);
        }
        auto lt = solve(root->left);
        auto rt = solve(root->right);

        if(root->val > lt.leftMax && root->val<rt.rightMin){
            sum = max(sum, root->val + lt.maxSum + rt.maxSum);
            return NodesValue((lt.maxSum+rt.maxSum+root->val), max(root->val,rt.leftMax), min(root->val,lt.rightMin) );
        }
   
        return NodesValue(max(lt.maxSum,rt.maxSum),INT_MAX,INT_MIN);
    }
    int maxSumBST(TreeNode *root)
    {
        solve(root);
        return sum;
    }

};
int main()
{

    return 0;
}