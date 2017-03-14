#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_set>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(NULL) {}
};


//ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
//{
//    std::unordered_set<ListNode*> st;

//    while(headA)
//    {
//        st.push(headA);
//        headA = headA->next;
//    }

//    while(headB)
//    {
//        if(st.count(headB))
//            return headB;
//        else
//            headB = headB->next;
//    }

//    return NULL;
//}


ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
{
    if(!headA || !headB)
        return NULL;

    int lenA = 1;
    int lenB = 1;

    ListNode* pA = headA, *pB = headB;
    while(pA->next)
    {
        ++ lenA;
        pA = pA->next;
    }

    while(pB->next)
    {
        ++ lenB;
        pB = pB->next;
    }

    if(pA != pB)
        return NULL;

    if(lenA > lenB)
    {
        for(int i = 1; i <= lenA - lenB; ++ i)
            headA = headA->next;
    }
    else
    {
        for(int i = 1; i <= lenB - lenA; ++ i)
            headB = headB->next;
    }

    while(headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }

    return headA;
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

