#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Fast and slow pointer approach

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        struct ListNode *a = head;
        struct ListNode *b = head;

        do
        {
            if (a == nullptr || b == nullptr)
            {
                return false;
            }
            a = a->next;
            b = b->next;
            if (b->next != nullptr)
            {
                b = b->next;
            }
        } while (a != b && a != nullptr && b != nullptr);

        return true;
    }
};

// hashmap approach

bool hasCycle(ListNode *head)
{
    if (head == NULL)
        return false;
    unordered_map<ListNode *, int> map;
    while (head != NULL)
    {
        if (map.count(head) > 0)
            return true;
        else
            map[head] = 1;
        head = head->next;
    }
    return false;
}

int main()
{

    return 0;
}