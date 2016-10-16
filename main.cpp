#include <iostream>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(NULL) {}
};


ListNode* mergeTwoList(ListNode* l1, ListNode* l2)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->next = NULL;
    node->val  = 0;

    ListNode* newList = node;
    ListNode* p = newList;

    while(l1 != NULL && l2 != NULL)
    {
        if(l1->val <= l2->val)
        {
            p->next = l1;
            l1 = l1->next;
            p  = p->next;
        }
        else
        {
            p->next = l2;
            l2 = l2->next;
            p  = p->next;
        }
    }

    while(l1 != NULL)
    {
        p->next = l1;
        l1 = l1->next;
        p  = p->next;
    }

    while(l2 != NULL)
    {
        p->next = l2;
        l2 = l2->next;
        p  = p->next;
    }

    return newList->next;
}

int main()
{
    ListNode* l1 = NULL, *l2 = NULL;
    ListNode* node;
    ListNode* p;

    node = (ListNode*)malloc(sizeof(ListNode));
    node->val = 1;
    node->next = NULL;
    l1 = node;
    p  = node;

    node = (ListNode*)malloc(sizeof(ListNode));
    node->val = 3;
    node->next = NULL;
    p->next = node;


    node = (ListNode*)malloc(sizeof(ListNode));
    node->val = 2;
    node->next = NULL;
    l2 = node;

    ListNode* newList = mergeTwoList(l1, l2);
    while(newList != NULL)
    {
        std::cout<<newList->val<<std::endl;
        newList = newList->next;
    }

    system("pause");
    return 0;
}

