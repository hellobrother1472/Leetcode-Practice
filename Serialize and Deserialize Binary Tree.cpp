#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <sstream>
#include  <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
        {
            return "";
        }
        string a = "";
        queue<TreeNode *> q;
        q.push(root);      // Push the root to the queue
        while (!q.empty()) // Until the queue is empty traverse
        {
            // make a vector level and push the val to take the value and store it in level and then push the left and right tree node of the present node and then perform same thing one by one.
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node == NULL)
                {
                    a.append("#,");
                }
                else
                {
                    a.append(to_string(node->val) + ",");
                }

                if (node != NULL)
                {
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        return a;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if(data.size()== 0){
            return NULL;
        }
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode*root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*node = q.front();
            q.pop();

            getline(s,str,',');
            if(str=="#"){
                root->left == NULL;
            }
            else{
                TreeNode*lftNode = new TreeNode(stoi(str));
                node->left = lftNode;
                q.push(lftNode);
            }

            getline(s,str,',');
            if(str=="#"){
                root->right == NULL;
            }
            else{
                TreeNode*rgtNode = new TreeNode(stoi(str));
                node->right = rgtNode;
                q.push(rgtNode);
            }
        }
        return root;
    }
};

int main()
{

    return 0;
}