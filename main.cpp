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

void inorder(TreeNode* root, TreeNode* &pre, TreeNode* &first, TreeNode* &second)
{
    if(root == NULL)
        return;

    if(root->left != NULL)
        inorder(root->left, pre, first, second);

    if(pre != NULL)
    {
        if(first == NULL  && root->val < pre->val)
            first = pre;
        else if(first != NULL && root->val > first->val)
        {
            second = pre;
            return;
        }
    }

    pre = root;
    if(root->right != NULL)
        inorder(root->right, pre, first, second);
}

void recoverTree(TreeNode* root)
{
    TreeNode* pre = NULL, *first = NULL, *second = NULL;
    inorder(root, pre, first, second);

    if(first != NULL)
    {
        if(second == NULL)
            second = pre;

        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
}

int main()
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = 1;
    node->left = NULL;
    node->right = NULL;

    TreeNode* root = node;

    node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = 2;
    node->left = NULL;
    node->right = NULL;

    root->right = node;

    node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = 3;
    node->left = NULL;
    node->right = NULL;

    root->right->left = node;



    system("pause");
    return 0;
}

