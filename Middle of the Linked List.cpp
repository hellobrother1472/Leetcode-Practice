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

// Just count the nodes, half it and then reach to that node.
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode *i = head;
        while(i){
            i = i->next;
            count++;
        }
        i = head;
        int mid = count/2;
        int iter = 0;
        while(iter<mid){
            i = i->next;
            iter++;
        }
        return i;
    }
};

// This method is called [TortoiseHare Method]. In this method their are two pointers first run 1 step and second run 2 steps. When second reach the end or becomes NULL then at that point the position of i is the mid.
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *iOne = head;
        ListNode *iTwo = head;
        while (iTwo)
        {
            iTwo = iTwo->next;
            if (iTwo)
                iTwo = iTwo->next;
            else
                break;
            
            iOne = iOne->next;
        }
        return iOne;
    }
};

int main()
{

    return 0;
}