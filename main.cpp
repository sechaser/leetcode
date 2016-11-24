#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct TreeNode
{
    int val;

    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode
{
    int val;

    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

TreeNode* solver(ListNode* &head, int l, int r)
{
    if(l > r)
        return NULL;

    int m = (l + r) / 2;
    TreeNode* left = solver(head, l, m - 1);
    TreeNode* root = new TreeNode(head->val);

    head = head->next;
    TreeNode* right = solver(head, m + 1, r);
    root->left  = left;
    root->right = right;

    return root;
}

TreeNode* sortedListToBST(ListNode* head)
{
    if(head == NULL)
        return NULL;

    ListNode* cur = head;
    int sz = 0;
    while(cur != NULL)
    {
        ++ sz;
        cur = cur->next;
    }

    return solver(head, 0, sz - 1);
}

void inorder(TreeNode* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        std::cout<<std::setw(4)<<root->val;
        inorder(root->right);
    }
}

int main()
{
    ListNode* node = new ListNode(1);
    ListNode* lis = node;

    node = new ListNode(2);
    lis->next = node;

    node = new ListNode(3);
    lis->next->next = node;

    TreeNode* root = sortedListToBST(lis);
    inorder(root);

    system("pause");
    return 0;
}

