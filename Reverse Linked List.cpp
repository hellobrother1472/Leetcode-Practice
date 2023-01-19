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

// Iterative
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *front = NULL;
        ListNode *mid = NULL;
        ListNode *end = head;
        while (end)
        {
            front = mid;
            mid = end;
            end = end->next;
            mid->next = front;
        }
        return mid;
    }
};

// Reccursive
class Solution
{
public:
    ListNode *ans = NULL;
    void reccReverseList(ListNode *front, ListNode *mid, ListNode *end)
    {
        if (end == NULL)
        {
            ans = mid;
            mid->next = front;
            return;
        }
        mid->next = front;
        reccReverseList(mid, end, end->next);
    }
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *front = NULL;
        ListNode *mid = head;
        ListNode *end = head->next;
        reccReverseList(front, mid, end);

        return ans;
    }
};

// Reccursive2

class Solution
{
public:
    ListNode *reverseList(ListNode *&head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *nnode = reverseList(head->next); // Here we get to the last node.
        head->next->next = head; // Apne next ke next ko khud ke upar point krr lo.
        head->next = NULL; // Apne next ko null krlo
        return nnode;
    }
};

int main()
{

    return 0;
}