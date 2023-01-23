#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// The approach is to simply remove the element at the odd index and place it to the end.
// Some catch in the question is that:
// after placing the odd index element at last I have to take back i such that flow remains same
// I have to record the initial last element (fixed) to stop infinite loop.
// If fixed itself is on odd index it means it will change and if it change than it affects condition of while loop, so if fixed is on odd index then before doing the shifting just make it's previous item be fixed.

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return head;
        int count = 0;
        ListNode*tail = head;
        // while loop to reach end
        while(tail->next){
            tail = tail->next;
        }
        ListNode*fixed = tail; // Storing the initial tail
        ListNode*i = head;
        ListNode*j = NULL;
        while(i && i!=fixed->next){
            if(count%2 == 0) {
                j = i;
                i = i->next;
            }
            else{
                // Make previous element fixed before shifting if fixed is on odd index.
                if(i == fixed){
                    fixed = j;
                }
                // just deleting the node and adding it to tail and making the new tail.
                j->next = i->next;
                i->next = NULL;
                tail->next = i;
                tail = i;
                i = j->next;
            }
            count++;
        }
        return head;
    }
};

int main(){

    return 0;
}