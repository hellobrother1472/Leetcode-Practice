#include <bits/stdc++.h>
using namespace std;

class node {
    public:
        int num;
        node* next;
        node(int val) {
            num = val;
            next = NULL;
        }
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 1) just map the first linked list and after that check in head B and return when we find common.
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int>mp;
        ListNode*i = headA;
        ListNode*j = headB;
        while(i){
            mp[i]++;
            i = i->next;
        }
        while(j){
            if(mp[j]) return j;
            j = j->next;
        }
        return NULL;
    }   
};
// 2) This question can also be done using stack, the logic is that the nodes after intersection is equal so we use stack for reverse iteration and pop the elements one by one from both stacks and store the poped item. The first time we got that element of the stack that is poped is not equal that means previous poped element is the intersection point.

// 3) As before intersection no. of nodes are different, so we find that difference by subtracting their length. Now we using this difference we start from same distance from intersection. So now simply move two pointers together and whenever they meet return it as the answer.

int getDifference(node* head1,node* head2) {
    int len1 = 0,len2 = 0;
    while(head1 != NULL || head2 != NULL) {
        if(head1 != NULL) {
            ++len1; head1 = head1->next;
        }
        if(head2 != NULL) {
            ++len2; head2 = head2->next;
        }
        
    }
    return len1-len2;//if difference is neg-> length of list2 > length of list1 else vice-versa
}
node* intersectionPresent(node* head1,node* head2) {
    int diff = getDifference(head1,head2);
    if(diff < 0) 
        while(diff++ != 0) head2 = head2->next; 
    else while(diff-- != 0) head1 = head1->next;
    while(head1 != NULL) {
        if(head1 == head2) return head1;
        head2 = head2->next;
        head1 = head1->next;
    }
    return head1;

}

// The difference of length method requires various steps to work on it. Using the same concept of difference of length, a different approach can be implemented. The process is as follows:-
// i) Take two dummy nodes for each list. Point each to the head of the lists.
// ii) Iterate over them. If anyone becomes null, point them to the head of the opposite lists and continue iterating until they collide.

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*d1 = headA;
        ListNode*d2 = headB;
        while(d1 != d2) {
            d1 = d1 == NULL? headB:d1->next;
            d2 = d2 == NULL? headA:d2->next;
        }
        return d1;
    }   
};

int main(){

    return 0;
}