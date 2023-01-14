#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int,int>> ans;
        Node*front = head;
        Node*end = head;
        while(end->next){
            end = end->next;
        }
        while(front != end){
            int sum = front->data + end->data;
            if(sum > target){
                end = end->prev;
            }
            else{
                if(sum == target){
                    pair<int,int> p(front->data, end->data);
                    ans.push_back(p);
                }
                front = front->next;
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}