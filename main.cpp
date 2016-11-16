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

std::vector<TreeNode*> solver(int min, int max)
{
    std::vector<TreeNode*> ret;

    if(min > max)
    {
        ret.push_back(NULL);
        return ret;
    }

    for(int i = min; i <= max; ++ i)
    {
        std::vector<TreeNode*> leftTree  = solver(min, i-1);
        std::vector<TreeNode*> rightTree = solver(i+1, max);

        for(int j = 0; j != leftTree.size(); ++ j)
        {
            for(int k = 0; k != rightTree.size(); ++ k)
            {
                TreeNode* root = new TreeNode(i);
                root->left  = leftTree[j];
                root->right = rightTree[k];
                ret.push_back(root);
            }
        }
    }

    return ret;
}

std::vector<TreeNode*> generateTrees(int n)
{
    if(n == 0)
        return std::vector<TreeNode*>{};
    return solver(1, n);
}

void traverseInorder(TreeNode* root)
{
    if(root != NULL)
    {
        traverseInorder(root->left);
        std::cout<<std::setw(4)<<root->val;
        traverseInorder(root->right);
    }
}

int main()
{
    std::vector<TreeNode*> res = generateTrees(3);

    for(std::vector<TreeNode*>::size_type i = 0; i != res.size(); ++ i)
    {
        traverseInorder(res[i]);
        std::cout<<std::endl;
    }

    system("pause");
    return 0;
}

