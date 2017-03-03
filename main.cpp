#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stack>

struct TreeNode
{
    int val;

    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

std::vector<int> preorderTraversal(TreeNode* root) {
    std::stack<TreeNode*> stk;
    std::vector<int> res;

    while(root || !stk.empty())
    {
        if(root)
        {
            stk.push(root);
            res.push_back(root->val);
            root = root->left;
        }
        else
        {
            root = stk.top();
            stk.pop();
            root = root->right;
        }
    }


    return res;
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

