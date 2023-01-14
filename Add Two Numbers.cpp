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

// by creating new list
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*i = l1;
        ListNode*j  = l2;
        int carry = 0; // initially the carry is 1
        ListNode*newHead = new ListNode(0); // creating a new list with starting element as zero (we will return newHead->next)
        ListNode*k = newHead; // assigning pointer to new list
        while(i || j){ // condition is such that even if one list came to end the while loop should not stop until both become null
            // if any of the list become null then I simly assigning it zero value.
            int num1 = (i==NULL) ? 0 : i->val;
            int num2 = (j == NULL) ? 0 : j->val;
            int sum = num1 + num2 + carry;
            // Now the conditions for sum>=10 and else is different as they both results in different value and carry value.
            if(sum >= 10){
                k->next = new ListNode(sum%10);
                k = k->next;
                carry = sum/10;
            }
            else{
                k->next = new ListNode(sum);
                k = k->next;
                carry = 0;
            }
            if(i){i = i->next;}
            if(j) {j = j->next;}
        }
        // if carry is still remaining it means we have to create a new node at last with the value in carry.
        if(carry){
            k->next = new ListNode(carry);
            k = k->next;
        }
        return newHead->next;
    }
};

// without creating new list (Explaination is same as above)

class Solution {
public:
    int diff(ListNode *a, ListNode*b){
        int n1 = 0,n2 = 0;
        ListNode*i = a;
        ListNode*j = b;
        while(i){
            n1++;
            i = i->next;
        }
        while(j){
            n2++;
            j = j->next;
        }
        return (n1-n2);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(diff(l1,l2)<0) return addTwoNumbers(l2,l1);
        ListNode*i = l1;
        ListNode*j  = l2;
        int carry = 0;
        while(i || j){
            int num1 = (i==NULL) ? 0 : i->val;
            int num2 = (j == NULL) ? 0 : j->val;
            int sum = num1 + num2 + carry;
            if(sum >= 10){
                i->val = sum%10;
                carry = sum/10;
            }
            else{
                i->val = sum;
                carry = 0;
            }
            if(i){i = i->next;}
            if(j) {j = j->next;}
        }
        if(carry){
            i = l1;
            while(i->next){
                i = i->next;
            }
            i->next = new ListNode(carry);
        }
        return l1;
    }
};

int main(){

    return 0;
}