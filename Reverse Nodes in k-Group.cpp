#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Approach
// To solve it I have to iterate the linked list and select the sub list and reverse it and then move forward. This requires 4 pointers. 2 for keeping the sublist and other to be before and after the list.
// Make 4 pointers front(front of sublist), end(end of sublist), before(before front) and after(after front).
// Then while we have front value we run a while loop and inside while loop run a for loop first which takes end to it's position according to given value of k.
// In this for loop if end becomes null it means the subsequence left is not the size of k and according to question we have to leave it as it is without reversing so I break from both the loop.
// After that reverse the sublist.
// after reversing, if before is NULL it means it is first set of sublist we are working on so the previous end value is now become our new head , if before is not NULL then make it's next point to the end value as it is the first value of the sublist after reversing.
// and make previous front->next = after (as it is the last value of new sublist after reversing).
// After that reset the question for next iteration making before = front, front = after and end = front.

class Solution {
public:
    void reverse(ListNode*head,ListNode*tail){
        ListNode*f = NULL;
        ListNode*m = NULL;
        ListNode*e = head;
        while(m != tail){
            f = m;
            m = e;
            e = e->next;
            m->next = f;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        ListNode*front = head;
        ListNode*end = head;
        ListNode*before = NULL;
        ListNode*after = end;
        while(front){
            for(int i = 1 ; i < k ; i++){
                if(end == NULL) break;
                end = end->next;
            }
            if(end == NULL) break;
            after = end->next;
            reverse(front,end);
            if(before == NULL){
                head = end;
            }
            else{
                before->next = end;
            }
            front->next = after;
            before = front;
            front = after;
            end = front;
        }
        return head;
    }
};

int main(){

    return 0;
}