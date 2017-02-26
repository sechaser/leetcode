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

ListNode* partition(ListNode* head, int x)
{
    if(head == NULL)
        return head;

    ListNode* small_head = (ListNode*)malloc(sizeof(ListNode));
    //small_head->next = NULL;
    ListNode* sp = small_head;

    ListNode* large_head = (ListNode*)malloc(sizeof(ListNode));
    //large_head->next = NULL;
    ListNode* lp = large_head;

    while(head != NULL)
    {
        if(head->val < x)
        {
            sp->next = head;
            //sp->next->next = NULL;
            head = head->next;
            sp = sp->next;
        }
        else
        {
            lp->next = head;
            //lp->next->next = NULL;
            head = head->next;
            lp = lp->next;
        }
    }

    lp->next = NULL;
    sp->next = large_head->next;

    return small_head->next;
}


int main()
{
    ListNode* node, *p, *lis1;
    for(int i = 0; i != 2; ++ i)
    {
        node = (ListNode*)malloc(sizeof(ListNode));
        node->val  = i+1;
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

    p = partition(lis1, 3);
    while(p != NULL)
    {
        std::cout<<std::setw(4)<<p->val;
        p = p->next;
    }
    std::cout<<std::endl;


    system("pause");
    return 0;
}

