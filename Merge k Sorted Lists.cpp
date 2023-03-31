#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Take two array at a time and merge and then go ahead and repeat at last we got correct answer.
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode * i = list1;
        ListNode * j = list2;
        ListNode*newHead = new ListNode(0);
        ListNode*tail = newHead;
        while(list1 && list2){
            ListNode* newNode;
            if(list1->val > list2->val){
                newNode = new ListNode(list2->val);
                list2 = list2->next;
            }
            else{
                newNode = new ListNode(list1->val);
                list1 = list1->next;
            }
            tail->next = newNode;
            tail = newNode;
        }   
        if(list1){
            while(list1){
                ListNode* newNode = new ListNode(list1->val);
                tail->next = newNode;
                tail = newNode;
                list1 = list1->next;
            }
        }
        if(list2){
            while(list2){
                ListNode* newNode = new ListNode(list2->val);
                tail->next = newNode;
                tail = newNode;
                list2 = list2->next;
            }
        }
        return newHead->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * ans = NULL;
        for(int i = 0 ; i < lists.size();i++){
            ans = mergeTwoLists(ans,lists[i]);
        }
        return ans;
    }
};

// With this merge two sorted list code it works

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == nullptr){
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * ans = NULL;
        for(int i = 0 ; i < lists.size();i++){
            ans = mergeTwoLists(ans,lists[i]);
        }
        return ans;
    }
};

// It uses appraoch of having an iterator in front of every linked list, and then comparing and making the answer linked list.
// We uses heap to implement the approach as we first put the first value in the heap of every linked list (to get the minimum), after getting the minimum on the top we just again push the top()->next after poping which resembles to taking pointer ahead in the respective linked list, after we get minimum of all k pointers from all the linked list.
// https://www.youtube.com/watch?v=RYJ3vs8qx10

class Solution {
public:
    class cmp{
        public:
        bool operator() (ListNode*l1 , ListNode *l2){
            return l1->val > l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>,cmp> q;
        for(int i = 0 ; i < lists.size() ; i++){
            if(lists[i] != NULL) q.push(lists[i]);
        }
        ListNode*ans = NULL;
        ans = new ListNode(1);
        ListNode * itr = ans;
        while(!q.empty()){
            ListNode * helper = q.top();
            q.pop();
            itr->next = new ListNode(helper->val);
            itr = itr->next;
            helper = helper->next;
            if(helper) q.push(helper);
        }
        return ans->next;
    }
};

int main(){
    return 0;
}