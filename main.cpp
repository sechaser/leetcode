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

int countNodes(TreeNode* root)
{
    if(root == NULL)
        return 0;

    int hl = 0, hr = 0;
    TreeNode* left = root, *right = root;
    while(left)
    {
        ++ hl;
        left = left->left;
    }

    while(right)
    {
        ++ hr;
        right = right->right;
    }

    if(hl == hr)
        return std::pow(2, hl) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
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

    std::vector<int> res = inorderTraversal(root);

    for(std::vector<int>::size_type i = 0; i != res.size(); ++ i)
        std::cout<<std::setw(4)<<res[i];
    std::cout<<std::endl;

    system("pause");
    return 0;
}

