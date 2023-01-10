#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Just find the collision point and run through the loop to count
int countNodesinLoop(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    int count = 1;
    Node *fast = head;
    Node *slow = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            Node *entry = slow->next; 
            while (slow != entry)
            {
                entry = entry->next;
                count++;
            }
            return count;
        }
    }
    return 0;
}

int main()
{

    return 0;
}