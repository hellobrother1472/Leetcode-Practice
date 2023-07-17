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
private:
    ListNode* reverseLL(ListNode*head){
        ListNode*front = NULL;
        ListNode*mid = NULL;
        ListNode*end = head;
        while(end){
            front = mid;
            mid = end;
            end = end->next;
            mid->next = front;
        }
        return mid;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);
        ListNode*ans = new ListNode(0);
        ListNode*ptr = ans;
        int carry = 0;

        while(l1 && l2){
            // cout << "l1 : " << l1->val << " " << "l2 : " << l2->val << endl;
            int x = l1->val, y = l2->val;
            int sum = x + y + carry;
            ListNode * temp;
            if(sum >= 10) {
                temp = new ListNode(sum % 10);
                carry = sum/10;
            }
            else{
                temp = new ListNode(sum);
                carry = 0;
            }
            ptr->next = temp;
            ptr = temp;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            // cout << "l1 : " << l1->val << endl;
            int sum = l1->val + carry;
            ListNode * temp;
            if(sum >= 10) {
                temp = new ListNode(sum % 10);
                carry = sum/10;
            }
            else{
                temp = new ListNode(sum);
                carry = 0;
            }
            ptr->next = temp;
            ptr = temp;
            l1 = l1->next;
        }

        while(l2){
            // cout << "l2 : " << l2->val << endl;
            int sum = l2->val + carry;
            ListNode * temp;
            if(sum >= 10) {
                temp = new ListNode(sum % 10);
                carry = sum/10;
            }
            else{
                temp = new ListNode(sum);
                carry = 0;
            }
            ptr->next = temp;
            ptr = temp;
            l2 = l2->next;
        }

        if(carry){
            ListNode * temp;
            temp = new ListNode(carry);
            carry = 0;
            ptr->next = temp;
            ptr = temp;
        }

        ListNode * newAns = ans->next;
        ans->next = NULL;
        ans = newAns;
        ans = reverseLL(ans);
        return ans;
    }
};

// Using linkedList 2 (same approach different execution)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* temp;
        while (head) {
            // Keep the next node.
             temp = head->next;
            // reverse the link
            head->next = prev;
            // Update the previous node and the current node.
            prev = head;
            head = temp;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r1 = reverseList(l1);
        ListNode* r2 = reverseList(l2);

        int totalSum = 0;
        int carry = 0;
        ListNode* ans = new ListNode();
        while (r1 || r2) {
            if (r1) {
                totalSum += r1->val;
                r1 = r1->next;
            }
            if (r2) {
                totalSum += r2->val;
                r2 = r2->next;
            }

            ans->val = totalSum % 10;
            carry = totalSum / 10;
            ListNode* head = new ListNode(carry);
            head->next = ans;
            ans = head;
            totalSum = carry;
        }

        return carry == 0 ? ans->next : ans;
    }
};

// Using stack
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;

        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int totalSum = 0, carry = 0;
        ListNode* ans = new ListNode();
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {
                totalSum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                totalSum += s2.top();
                s2.pop();
            }

            ans->val = totalSum % 10;
            carry = totalSum / 10;
            ListNode* newNode = new ListNode(carry);
            newNode->next = ans;
            ans = newNode;
            totalSum = carry;
        }

        return carry == 0 ? ans->next : ans;
    }
};


int main(){

    return 0;
}