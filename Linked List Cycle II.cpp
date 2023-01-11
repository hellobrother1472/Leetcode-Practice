#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Approach 1
// Iterate the given list.
// For each node visited by the head pointer, check if the node is present in the hash table.
// If yes, the loop detected
// If not, insert the node in the hash table and move the head pointer ahead.
// If the head reaches null, then the given list does not have a cycle in it.

ListNode* detectCycle(ListNode* head) {
    unordered_set<ListNode*> st;
    while(head != NULL) {
        if(st.find(head) != st.end()) return head;
        st.insert(head);
        head = head->next;
    }
    return NULL;
}

// Approach 2
// 1) First I am using slow and fast pointer approach. If it fails it means no cycle exists and if it pass I will get one point in the cycle. (where iOne==iTwo)
// 2) Then after getting the point I am making third pointer, that third pointer will now be place before iOne (as I want to check if previous point is in cycle or not by iterating iTwo). Now if iTwo meets iThree that means iThree is in the cycle so now make iThree new iOne and break. Else if iTwo meets iOne, it means thier is no iThree in cycle it means iOne is the answer.
// 3) if iOne reaches head it means to stop and return head. (because iOne points to confirmed element in the cycle)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode*iOne = head;
        ListNode*iTwo = head->next;
        while(iTwo != NULL && iTwo != iOne){
            iTwo = iTwo->next;
            if(iTwo && iTwo->next){
                iTwo = iTwo->next;
            }
            else{
                return NULL;
            }
            iOne = iOne->next;
        }
        ListNode*iThree = head;
        while(iOne != head){
            while(iThree->next != iOne){
                iThree = iThree->next;
            }
            do{
                iTwo = iTwo->next;
                
                if(iTwo == iOne){
                    return iOne;
                }
                if(iTwo == iThree){
                    iOne = iThree;
                    iThree = head;
                    break;
                }
            }while(iTwo != iThree);
        }
        
        
        return head;
    }
};

// Approach 3
// Similar to approach two, but after finding the equating point, move the slow and the entry pointer ahead by single steps until they collide. When they collide it means that is the answer.
// The logic behind this logic is that, let us suppose if the linked list is fully circular, then the fast and slow pointer will meet at head. But if that is not the case they will meet at pos-(no. of nodes before pos). That's why after getting the collision point we make new node and move slow and new node one step only.
// For more :- https://www.youtube.com/watch?v=QfbOhn0WZ88&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=38

ListNode* detectCycle(ListNode* head) {
    if(head == NULL||head->next == NULL) return NULL;
        
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* entry = head;
        
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
            
        if(slow == fast) {
            while(slow != entry) {
                slow = slow->next;
                entry = entry->next;
            }
            return slow;
        }
    }
    return NULL;
}


int main(){

    return 0;
}

