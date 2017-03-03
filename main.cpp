#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(NULL) {}
};

ListNode* findMid(ListNode* head)
{
    ListNode* fast = head, *low = head;

    while(fast && fast->next)
    {
        fast = fast->next;
        if(fast->next)
            fast = fast->next;
        low = low->next;
    }

    return low;
}

ListNode* reverseList(ListNode* head)
{
    if(!head)
        return NULL;
    ListNode* pre = head, *cur = head->next;

    while(cur)
    {
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    head->next = NULL;

    return pre;
}

void reorderList(ListNode* head)
{
    if(!head)
        return NULL;

    ListNode* mid = findMid(head);
    ListNode* right = reverseList(mid);

    ListNode* left = head;
    while(right && right->next)
    {
        ListNode* leftNext  = left->next;
        ListNode* rightNext = right->next;
        left->next = right;
        right->next = leftNext;
        left  = leftNext;
        right = rightNext;
    }

}


int main()
{
    ListNode* node, *p, *lis1, *lis2, *lis3;
    for(int i = 0; i != 5; ++ i)
    {
        node = (ListNode*)malloc(sizeof(ListNode));
        node->val  = i;
        node->next = NULL;

        if(i == 0)
        {
            lis1 = node;
            p    = node;
        }
        else
        {
            p->next = node;
            p       = node;
        }
    }


    for(int i = 0; i != 5; ++ i)
    {
        node = (ListNode*)malloc(sizeof(ListNode));
        node->val  = i+5;
        node->next = NULL;

        if(i == 0)
        {
            lis2 = node;
            p    = node;
        }
        else
        {
            p->next = node;
            p       = node;
        }
    }

    for(int i = 0; i != 5; ++ i)
    {
        node = (ListNode*)malloc(sizeof(ListNode));
        node->val  = i;
        node->next = NULL;

        if(i == 0)
        {
            lis3 = node;
            p    = node;
        }
        else
        {
            p->next = node;
            p       = node;
        }
    }


    system("pause");
    return 0;
}

