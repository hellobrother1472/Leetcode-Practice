#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

class Nodevalue{
    public:
    int maxNode,minNode,maxSize;
    Nodevalue(int minNode,int maxNode,int maxSize){
        this->maxNode = maxNode;
        this->maxSize = maxSize;
        this->minNode = minNode;
    }
};


Nodevalue helper(TreeNode * root){
    if(!root) return Nodevalue(INT_MAX,INT_MIN,0);
    auto left = helper(root->left);
    auto right = helper(root->right);
    if(left.maxNode < root->data && root->data < right.minNode){
        return Nodevalue(min(root->data,left.minNode), max(root->data,right.maxNode),left.maxSize+right.maxSize+1);
    }
    return Nodevalue(INT_MIN, INT_MAX,max(left.maxSize, right.maxSize));
}

int largestBST(TreeNode * root){
    // Write your code here.
    return helper(root).maxSize;
}


int main(){
    return 0;
}