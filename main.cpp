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

void findPath(TreeNode* root, std::vector<int>& path, std::vector<std::vector<int> >& paths)
{
    path.push_back(root->val);

    if(!root->left && !root->right)
    {
        paths.push_back(path);
        path.pop_back();
        return;
    }

    if(root->left)
        findPath(root->left, path, paths);

    if(root->right)
        findPath(root->right, path, paths);
    path.pop_back();
}

std::vector<std::string> binaryTreePaths(TreeNode* root)
{
    std::vector<std::vector<int> > paths;
    std::vector<int> path;
    std::vector<std::string> res;

    if(!root)
        return res;

    findPath(root, path, paths);
    for(int i = 0; i < paths.size(); ++ i)
    {
        std::string s = std::to_string(paths[i][0]);
        for(int j = 1; j < paths[i].size(); ++ j)
            s = s + "->" + std::to_string(paths[i][j]);
        res.push_back(s);
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


    std::vector<std::string> res = binaryTreePaths(root);
    for(int i = 0; i < res.size(); ++ i)
        std::cout<<res[i]<<std::endl;

    system("pause");
    return 0;
}

