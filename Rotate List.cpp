#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// rather than rotation one by one just find the index from where we have to break the linkage.
// if k's value > length then we have to modify the k value and we can observe that we have to take it's mode
// After finding k value the index = length-k;
// go to that point with trailing pointer, break the linkage, iterate to the end of broken list and make point it's next to the head and make the starting of broken list head.
class Solution {
public:
    int findLength(ListNode*head){
        int length = 0;
        ListNode*i = head;
        // ListNode*j = NULL;
        while(i){
            length++;
            i = i->next;
        }
        return length;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        int length = findLength(head);
        if(k%length == 0) return head;
        if(k>length){
            k = k%length;
        }
        ListNode*i = head;
        ListNode*j = NULL;
        int index = length - k;
        while(index != 0){
            j = i;
            i = i->next;
            index--;
        }
        j->next = NULL;
        ListNode*iter = i;
        while(iter->next){
            iter = iter->next;
        }
        iter->next = head;
        head = i;
        return head;
    }
};

int main(){

    return 0;
}