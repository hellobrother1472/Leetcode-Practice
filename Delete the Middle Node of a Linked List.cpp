#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Find the middle index and delete it.
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode*i = head;
        // count the nodes
        int num = 0;
        while(i){
            num++;
            i = i->next;
        }
        num = num/2;
        i = head;
        ListNode* j = NULL;
        // reach to that index
        while(num != 0){
            j = i;
            i = i->next;
            num--;
        }
        cout << i->val;
        j->next = i->next;
        i->next = NULL;
        return head;
    }
};

int main(){

    return 0;
}