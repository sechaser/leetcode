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


void inOrder(TreeNode* root, std::vector<int>& res)
{
    if(root)
    {
        inOrder(root->left, res);
        res.push_back(root->val);
        inOrder(root->right, res);
    }
}

int kthSmallest(TreeNode* root, int k) {
    if(root == NULL)
        return 0;

    std::vector<int> res;
    inOrder(root, res);

    return res[k-1];
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

    std::cout<<kthSmallest(root, 1)<<std::endl;

    system("pause");
    return 0;
}

