#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Just pushing the value to the vector and sorting the vector and making another linked list
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL ) return head;
        vector<int>v;
        ListNode*i = head;
        while(i){
            v.push_back(i->val);
            i = i->next;
        }
        sort(v.begin(),v.end());
        ListNode* temp = new ListNode(v[0]);
        head = temp;
        for(int j = 1 ; j<v.size() ; j++){
            ListNode* n = new ListNode(v[j]);
            temp->next = n;
            temp = n;
        }
        return head;
    }
};

int main(){

    return 0;
}