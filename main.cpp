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

//**************************************************Time limit exceed***************************************
//ListNode* rotateRight(ListNode* head, int k)
//{
//    if(head == NULL || head->next == NULL || k == 0)
//        return head;

//    ListNode* p = head;
//    while(k > 0)
//    {
//        p = p->next;
//        -- k;

//        if(p == NULL)
//            p = head;
//    }

//    if(p == head)
//        return head;

//    ListNode* q = head;
//    while(p->next != NULL)
//    {
//        p = p->next;
//        q = q->next;
//    }

//    ListNode* newHead = q->next;
//    q->next = NULL;
//    p->next = head;

//    return newHead;
//}

ListNode* rotateRight(ListNode* head, int k)
{
    if(head == NULL || head->next == NULL || k == 0)
        return head;

    ListNode* p = head;
    int len = 0;
    while(p != NULL)
    {
        ++ len;
        p = p->next;
    }

    k = k % len;
    if(k == 0)
        return head;

    p = head;
    while(k > 0)
    {
        p = p->next;
        -- k;
    }

    ListNode* q = head;
    while(p->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    ListNode* newHead = q->next;
    q->next = NULL;
    p->next = head;

    return newHead;
}


int main()
{
    ListNode* node, *p, *lis1;
    for(int i = 0; i != 5; ++ i)
    {
        node = (ListNode*)malloc(sizeof(ListNode));
        node->val  = i + 1;
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

    ListNode* q = rotateRight(lis1, 18);
    while(q != NULL)
    {
        std::cout<<q->val<<std::endl;
        q = q->next;
    }

    system("pause");
    return 0;
}

