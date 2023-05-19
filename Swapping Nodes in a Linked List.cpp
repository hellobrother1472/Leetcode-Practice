#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int size = 0;
        ListNode * i = head;
        while(i){
            size++;
            i = i->next;
        }
        int first = k-1;
        int second = size-k;
        i = head;
        ListNode*j = head;
        while(first>0){
            i = i->next;
            first--;
        }
        while(second>0){
            j = j->next;
            second--;
        }
        int temp = i->val;
        i->val = j->val;
        j->val = temp;
        return head;
    }
};

// Single pass
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int size = 0;
        ListNode * i = head;
        while(i){
            size++;
            i = i->next;
        }
        int first = k-1;
        int second = size-k;
        i = head;
        ListNode*j = head;
        while(first>0){
            i = i->next;
            first--;
        }
        while(second>0){
            j = j->next;
            second--;
        }
        int temp = i->val;
        i->val = j->val;
        j->val = temp;
        return head;
    }
};

int main(){

    return 0;
}