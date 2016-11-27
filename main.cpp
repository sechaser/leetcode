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

void solver(TreeNode* root, int sum, std::vector<int>& path, std::vector<std::vector<int> >& allPaths)
{
    if(root == NULL)
        return;

    sum = sum - root->val;
    path.push_back(root->val);

    if(root->left == NULL && root->right == NULL)
    {
        if(sum == 0)
            allPaths.push_back(path);
    }
    else
    {
        if(root->left != NULL)
            solver(root->left, sum, path, allPaths);
        if(root->right != NULL)
            solver(root->right, sum, path, allPaths);
    }

    path.pop_back();
}

std::vector<std::vector<int> > pathSum(TreeNode* root, int sum)
{
    std::vector<int> path;
    std::vector<std::vector<int> > allPaths;
    solver(root, sum, path, allPaths);

    return allPaths;
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

    std::vector<std::vector<int> > res = pathSum(root, 2);
    for(std::vector<std::vector<int> >::size_type i = 0; i != res.size(); ++ i)
    {
        for(std::vector<int>::size_type j = 0; j != res[i].size(); ++ j)
            std::cout<<std::setw(4)<<res[i][j];
        std::cout<<std::endl;
    }


    system("pause");
    return 0;
}

