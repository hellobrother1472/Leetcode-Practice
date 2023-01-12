#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Just get the index of the node and remove it.
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL && n == 1) return NULL; 
        int length = 0;
        ListNode* i = head;
        while(i->next){
            i = i->next;
            // cout << i->val << endl;
            length++;
        }
        int index = length - n + 1;
        cout << length << " " << index << endl;
        if(index>length) return head;
        i = head;
        ListNode*j = i;
        while(i->next && index){
            j = i;
            i = i->next;
            index--;
            // cout << i->val<<endl;
        }
        if(i == head) return head->next;
        // cout << i->val;
        j->next = i->next;
        i->next = NULL;
        return head;
    }
};

int main(){

    return 0;
}