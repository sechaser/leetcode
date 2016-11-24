#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_map>

struct TreeNode
{
    int val;

    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void solver(std::vector<int>& res, TreeNode* root)
{
    if(root != NULL)
    {
        solver(res, root->left);
        res.push_back(root->val);
        solver(res, root->right);
    }
}

TreeNode* solver(std::vector<int>& preorder, int preL, int preR, std::vector<int>& inorder, int inL, int inR,
                 std::unordered_map<int, int>& mp)
{
    if(preL > preR || inL > inR)
        return NULL;

    TreeNode* root = new TreeNode(preorder[preL]);
    int index = mp[preorder[preL]];

    root->left  = solver(preorder, preL + 1, preL + (index - inL), inorder, inL, index - 1, mp);
    root->right = solver(preorder, preL + (index - inL) + 1, preR, inorder, index + 1, inR, mp);

    return root;
}

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
{
    if(preorder.empty() || inorder.empty())
        return NULL;

    std::unordered_map<int, int> mp;
    for(std::vector<int>::size_type i = 0; i != inorder.size(); ++ i)
        mp[inorder[i]] = i;

    return solver(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
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
    std::vector<int> preOrder{1, 2, 4, 5, 3, 6, 7};
    std::vector<int> inOrder {4, 2, 5, 1, 6, 3, 7};

    TreeNode* root = buildTree(preOrder, inOrder);
    inorder(root);

    system("pause");
    return 0;
}

