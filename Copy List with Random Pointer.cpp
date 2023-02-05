#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Wrong answer not working in the case in which two nodes have equal random value and random's next value. The approach uses these two parameters to identify a node uniquely.
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* newHead = new Node(0);
        Node*i = head;
        Node*j = newHead;
        while(i){
            Node* temp = new Node(i->val);
            j->next = temp;
            j = temp;
            i = i->next;
        }
        i = head;
        j = newHead->next;
        while(i){
            if(i->random == NULL){
                j->random = NULL;
                i = i->next;
                j = j->next;
                continue;
            }

            int random_node_val = i->random->val;
            int random_node_next_val;
            Node* iter = newHead->next;
            if(i->random->next){
                random_node_next_val = i->random->next->val;
            }
            else{
                while(iter->next){
                    iter = iter->next;
                }
                j->random = iter;
                i = i->next;
                j = j->next;
                continue;
            }
            while(iter->next){
                if(iter->val == random_node_val && iter->next->val == random_node_next_val){
                    break;
                }
                iter = iter->next;
            }
            j->random = iter;
            i = i->next;
            j = j->next;
        }
        return newHead->next;
    }
};

// Detailed explaination - https://takeuforward.org/data-structure/clone-linked-list-with-random-and-next-pointer/
// Solution using map. Just use map to store the node and it's deep node with it and random is adjusted according to that further.
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* newHead = new Node(0);
        Node*i = head;
        Node*j = newHead;
        map<Node*, Node*>mp;
        // making of new deep copy with next pointers only and storing it in map.
        while(i){
            Node* temp = new Node(i->val);
            j->next = temp;
            j = temp;
            mp[i] = j;
            i = i->next;
        }
        i = head;
        j = newHead->next;
        // accesing corresponding value as stored in map;
        while(i){
            j->random = mp[i->random];
            i = i->next;
            j = j->next;
        }
        return newHead->next;
    }
};


// Create deep nodes of all nodes. Instead of storing these nodes in a hashmap, we will point it to the next of the original nodes.
// Take a pointer, say itr, point it to the head of the list. This will help us to point random pointers as per the original list. This can be achieved by itr->next->random = itr->random->next
// Use three pointers. One dummy node whose next node points to the first deep node. itr pointer at the head of the original list and fast which is two steps ahead of the itr. This will be used to separate the original linked list with the deep nodes list.
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* newHead = new Node(0);
        Node*i = head;
        // Make the new list by merging
        while(i){
            Node* temp = new Node(i->val);
            temp->next = i->next;
            i->next = temp;
            i = i->next->next;
        }

        // connect the randoms
        i = head;
        while(i){
            if(i->random) i->next->random = i->random->next;
            i = i->next->next;
        }
        // Now seperate original and deep copy list.
        i = head;
        Node*j = newHead;
        newHead->next = head->next;
        j = newHead->next;
        if(j->next == NULL){ // case if initially j->next == NULL before while loop.
            i->next = NULL;
            return newHead->next;
        }
        while(j->next){
            i->next = j->next;
            j->next = j->next->next;
            i = i->next;
            j = j->next;
            if(j->next == NULL) i->next = NULL;
        }
        return newHead->next;
    }
};
int main(){

    return 0;
}