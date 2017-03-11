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

ListNode* sortList(ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return head;

    ListNode* fast = head, *slow = head;
    while(fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    fast = slow->next;
    slow ->next = NULL;

    slow = sortList(head);
    fast = sortList(fast);

    return mergeList(slow, fast);
}

ListNode* mergeList(ListNode* head1, ListNode* head2)
{
    ListNode* dummy = new ListNode(0);
    ListNode* p = dummy;

    while(head1 && head2)
    {
        if(head1->val <= head2->val)
        {
            p->next = head1;
            head1 = head1->next;
        }
        else
        {
            p->next = head2;
            head2 = head2->next;
        }
        p = p->next;
    }

    if(head1)
        p->next = head1;
    if(head2)
        p->next = head2;

    return dummy->next;
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

