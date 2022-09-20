#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    void assignParent(map<TreeNode*,TreeNode*>&m,TreeNode*root){
        if(root == NULL || (root->left == NULL && root->right == NULL)){
            return;
        }
        if(root->left){
            m[root->left] = root;
        } 
        if(root->right){
            m[root->right] = root;
        } 
        assignParent(m,root->left);
        assignParent(m,root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        map<TreeNode*,TreeNode*> m;
        // Assigning the parents to the node.
        assignParent(m,root);
        
        // taking the radial step in all direction one step at a time and visited array is taking care of what node we already visited.
        int distance = 0;
        queue<TreeNode*>q;
        vector<int>visited;
        q.push(target);
        while(distance < k){
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode*curr = q.front();
                visited.push_back(curr->val);
                q.pop();
                // Left
                if(curr->left && !count(visited.begin(),visited.end(),curr->left->val)){
                    q.push(curr->left);
                }      
                // Right   
                if(curr->right && !count(visited.begin(),visited.end(),curr->right->val)){
                    q.push(curr->right);
                }
                // top 
                if(m[curr] && !count(visited.begin(),visited.end(),m[curr]->val)){
                    q.push(m[curr]);
                }                
            }
            
            distance++;
            if(distance == k){
                break;
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};  

// Using map instead of visited vector
class Solution {
public:

    void assignParent(map<TreeNode*,TreeNode*>&m,TreeNode*root){
        if(root == NULL || (root->left == NULL && root->right == NULL)){
            return;
        }
        if(root->left){
            m[root->left] = root;
        } 
        if(root->right){
            m[root->right] = root;
        } 
        assignParent(m,root->left);
        assignParent(m,root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        map<TreeNode*,TreeNode*> m;
        // Assigning the parents to the node.
        assignParent(m,root);
        
        // taking the radial step in all direction one step at a time and visited array is taking care of what node we already visited.
        int distance = 0;
        queue<TreeNode*>q;
        // vector<int>visited;
        map<TreeNode*,bool>visited;
        q.push(target);
        while(distance < k){
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode*curr = q.front();
                visited[curr] = true;
                q.pop();
                // Left
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                }      
                // Right   
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                }
                // top 
                if(m[curr] && !visited[m[curr]]){
                    q.push(m[curr]);
                }                
            }
            
            distance++;
            if(distance == k){
                break;
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};  

// Reccursive Solution
class Solution {
public:
    
    vector<TreeNode*>nodePath(TreeNode* root,TreeNode*target){
        
        if(root == NULL)
            return {};
    
        if(root->val ==target->val)
            return {root};
        
        vector<TreeNode*>ans;
        
        ans = nodePath(root->left,target);
        
        if(ans.size()>0){
            ans.push_back(root);
            return ans ;
        }
        
        ans = nodePath(root->right,target);
        
        if(ans.size()>0){
            ans.push_back(root);
            return ans;
        }
        
        return {};
        
    }
    
    vector<int>ans;
    
    void findDown(TreeNode* root,int k,int level){
        
        if(root == NULL)
            return;
        
        if(k==level){
            ans.push_back(root->val);
            return;
        }
        
        findDown(root->left,k,level+1);
        findDown(root->right,k,level+1);
        
    }
    
    void findNodes(TreeNode* root,int level,int k, TreeNode* danger){
        
        if(root == NULL)
            return ;
        
        if(root == danger)
            return ;
        
        if(level == k){
            ans.push_back(root->val);
            return;
        }
        
        findNodes(root->left,level+1,k,danger);
        findNodes(root->right,level+1,k,danger);
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<TreeNode*>path = nodePath(root,target);
        
        findDown(path[0],k,0);
        
        for(int ctr = 1 ; ctr < path.size();ctr++){
            findNodes(path[ctr],0,k-ctr,path[ctr-1]);
        }
        
        return ans ;
        
    }
};

int main(){
    

    return 0;
}