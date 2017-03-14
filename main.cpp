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

ListNode* oddEvenList(ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return head;

    ListNode* oddHead  = new ListNode(0);
    ListNode* evenHead = new ListNode(0);
    ListNode* p1 = oddHead, *p2 = evenHead;

    bool isOdd = 1;
    while(head)
    {
        if(isOdd)
        {
            p1->next = head;
            p1 = p1->next;
        }
        else
        {
            p2->next = head;
            p2 = p2->next;
        }

        isOdd = !isOdd;
        head = head->next;
    }

    p2->next = NULL;
    p1->next = evenHead->next;

    return oddHead->next;
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

