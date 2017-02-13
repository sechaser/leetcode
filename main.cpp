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

void solver(TreeNode* root, int curSum, int& sum)
{
    curSum = curSum * 10 + root->val;
    if(root->left == NULL && root->right == NULL)
        sum += curSum;

    if(root->left)
        solver(root->left, curSum, sum);
    if(root->right)
        solver(root->right, curSum, sum);
}

int sumNumbers(TreeNode* root)
{
    if(root == NULL)
        return 0;

    int sum = 0;
    solver(root, 0, sum);

    return sum;
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
    root->left = node;

    std::cout<<sumNumbers(root)<<std::endl;

    system("pause");
    return 0;
}

