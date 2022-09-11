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

// This is my approach, the answer is correct but it includes many if statement. These if statements are due to negetive numbers and the demand of the question
class Solution { 
public:
    int sum = INT_MIN;
    int findSum(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        int lt = findSum(root->left);
        int rt = findSum(root->right);
        
        if(root->val > sum){
            sum = root->val;
        }
        if(root->val+lt > sum){
            sum = root->val+lt;
        }
        if(root->val+rt > sum){
            sum = root->val+rt;
        }
    
        if(lt+rt+root->val > sum){
            sum = lt+rt+root->val;
        }
        if(root->val > max(lt,rt)+root->val){
            return root->val;
        }
        
        return max(lt,rt)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int alter = findSum(root);
        return max(alter,sum);
    }
};

// Dealing with the above problem here is the solution for it. We have to just ignore negetive numbers and return 0 instead of it.

class Solution2 { 
public:
    int sum = INT_MIN;
    int findSum(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        int lt = max(0,findSum(root->left));
        int rt = max(0,findSum(root->right));
    
        if(lt+rt+root->val > sum){
            sum = lt+rt+root->val;
        }
        
        return max(lt,rt)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int alter = findSum(root);
        return max(alter,sum);
    }
};

int main()
{

    return 0;
}