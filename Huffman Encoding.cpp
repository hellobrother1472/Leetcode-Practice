#include <bits/stdc++.h>
using namespace std;

// Applying concept of Huffman coding

// Node for making the tree.
class Node {
    public:
    Node * left;
    Node * right;
    int val;
    
    Node(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

class cmp{
    public:
    bool operator()(Node *a, Node*b){
        return a->val > b->val;
    }
};

class Solution
{
	public:
	    void func(Node * root, vector<string>&ans, string s){
	        if(root->left == NULL && root->right == NULL) {
	            ans.push_back(s);
	            return;
	        }
	        
	        func(root->left, ans, s+'0');
	        func(root->right, ans, s+'1');
	    }
	    
		vector<string> huffmanCodes(string s,vector<int>f,int n)
		{
		    // Code here
		    priority_queue<Node*, vector<Node*>, cmp> minHeap;
		    for(int i; i<n; i++){
		        Node * newNode = new Node(f[i]);
		        minHeap.push(newNode);
		    }
		    
		    while(minHeap.size()>1){
		        Node * l = minHeap.top();
		        minHeap.pop();
		        
		        Node *r = minHeap.top();
		        minHeap.pop();
		        
		        Node * nNode = new Node(l->val + r->val);
		        nNode->left = l;
		        nNode->right = r;
		        
		        minHeap.push(nNode);
		    }
		    
		    Node * root = minHeap.top();
		    vector<string>ans;
		    string dummy = "";
		    func(root,ans,dummy);
		    return ans;
		}
};

int main(){

    return 0;
}