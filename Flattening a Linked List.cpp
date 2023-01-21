#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
// Using the concept of merging two sorted list. And using while loop sorting n list. Create new list by sorting two and the resultant list becomes new list and then merge it with third and so on.

// Iteratively
Node *mergeTwoLists(Node *list1, Node *list2)
{
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    Node *i = list1;
    Node *j = list2;
    Node *newHead = new Node(0);
    Node *tail = newHead;
    while (list1 && list2)
    {
        Node *newNode;
        if (list1->data > list2->data)
        {
            newNode = new Node(list2->data);
            list2 = list2->bottom;
        }
        else
        {
            newNode = new Node(list1->data);
            list1 = list1->bottom;
        }
        tail->bottom = newNode;
        tail = newNode;
    }
    if (list1) tail->bottom = i;
    if (list2) tail->bottom = j;
    return newHead->bottom;
}
Node *flatten(Node *root)
{
   if(root == NULL || root->next == NULL) return root;
   Node* newRoot;
   newRoot=  mergeTwoLists(root, root->next);
   Node*i = root->next->next;
   while(i){
       newRoot = mergeTwoLists(newRoot,i);
       i = i->next;
   }
   return newRoot;
}



// Reccursively

Node* mergeTwoLists(Node* a, Node* b) {
    
    Node *temp = new Node(0);
    Node *res = temp; 
    
    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            temp->bottom = a; 
            temp = temp->bottom; 
            a = a->bottom; 
        }
        else {
            temp->bottom = b;
            temp = temp->bottom; 
            b = b->bottom; 
        }
    }
    
    if(a) temp->bottom = a; 
    else temp->bottom = b; 
    
    return res -> bottom; 
    
}
Node *flatten(Node *root)
{
   
        if (root == NULL || root->next == NULL) 
            return root; 
  
        // recur for list on right 
        root->next = flatten(root->next); 
  
        // now merge 
        root = mergeTwoLists(root, root->next); 
  
        // return the root 
        // it will be in turn merged with its left 
        return root; 
}


int main()
{

    return 0;
}