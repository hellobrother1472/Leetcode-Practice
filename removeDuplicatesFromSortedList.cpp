#include <iostream>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *p = head;
        ListNode *q = head->next;

        while(q){
            if(p->val == q->val){
                p->next = q->next;
                q = p->next;
            }
            else{
                p = q;
                q = q->next;
            }
        }

        return head;
    }
};


int main()
{

    return 0;
}