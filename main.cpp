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

TreeNode* solver(std::vector<int>& inorder, int inL, int inR, std::vector<int>& postorder, int postL, int postR,
                 std::unordered_map<int, int>& mp)
{
    if(inL > inR || postL > postR)
        return NULL;

    TreeNode* root = new TreeNode(postorder[postR]);
    int index = mp[postorder[postR]];

    root->left  = solver(inorder, inL, index - 1, postorder, postL, postL + (index - inL) - 1, mp);
    root->right = solver(inorder, index + 1, inR, postorder, postL + (index - inL), postR - 1, mp);

    return root;
}

TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder)
{
    if(inorder.empty() || postorder.empty())
        return NULL;

    std::unordered_map<int, int> mp;
    for(std::vector<int>::size_type i = 0; i != inorder.size(); ++ i)
        mp[inorder[i]] = i;

    return solver(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, mp);
}

void inorderTraversal(TreeNode* root)
{
    if(root != NULL)
    {
        inorderTraversal(root->left);
        std::cout<<std::setw(4)<<root->val;
        inorderTraversal(root->right);
    }
}

int main()
{
    std::vector<int> inorder{4,2,5,1,6,3,7};
    std::vector<int> postorder{4,5,2,6,7,3,1};

    TreeNode* root = buildTree(inorder, postorder);
    inorderTraversal(root);

    system("pause");
    return 0;
}

