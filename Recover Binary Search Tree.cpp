#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <utility>

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

// Getting all the violating elements and swaping the min and max of it.
class Solution
{
public:
    vector<TreeNode*>v;
    TreeNode* Min =new TreeNode(INT_MAX);
    TreeNode* Max =new TreeNode(INT_MIN);
    void swap(TreeNode*x,TreeNode*y){
        int temp = x->val;
        x->val = y->val;
        y->val = temp;
    }
    void validate(TreeNode*root, TreeNode* min,TreeNode* max){
        if(root == NULL){
            return;
        }
        if(root->val >= max->val){
            v.push_back(root);
            v.push_back(max);
        }
        if(root->val < min->val){
            v.push_back(root);
            v.push_back(min);
        }
        validate(root->left,min,root);
        validate(root->right,root,max);
    }
    void recoverTree(TreeNode *root)
    {
        TreeNode*min = new TreeNode(INT_MIN);
        TreeNode*max = new TreeNode(INT_MAX);
        validate(root,min,max);
        for(int i = 0;i<v.size();i++){
            if(v[i]->val < Min->val){
                Min = v[i];
            }
            if(v[i]->val > Max->val){
                Max = v[i];
            }
        }
        swap(Min,Max);
    }
};

// Second way is to get inorder and comparing the tree and changing the value accordingly.

class Solution
{
public:
    TreeNode*front;
    TreeNode*last;
    TreeNode*middle;
    TreeNode*prev;
    void swap(TreeNode*x,TreeNode*y){
        int temp = x->val;
        x->val = y->val;
        y->val = temp;
    }
    
    void inorder(TreeNode *root){
        if(root == NULL){
            return;
        }

        inorder(root->left);
        if(prev && (prev->val > root->val)){
            if(front == NULL){
                front = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode *root)
    {
        prev=front=middle=last=NULL;
        // prev= new TreeNode(INT_MIN)
        inorder(root);
        if(front&&last){swap(front,last);}
        else if(front&&middle){swap(front,middle);}
    }
};


int main()
{

    return 0;
}