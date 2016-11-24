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

TreeNode* solver(std::vector<int>& nums, int l, int r)
{
    if(l > r)
        return NULL;

    int m = (l + r) / 2;
    TreeNode* root = new TreeNode(nums[m]);
    root->left  = solver(nums, l, m - 1);
    root->right = solver(nums, m + 1, r);

    return root;

}

TreeNode* sortedArrayToBST(std::vector<int>& nums)
{
    TreeNode* root = NULL;
    if(nums.empty())
        return root;
    return solver(nums, 0, nums.size() - 1);
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
    std::vector<int> nums {1, 2, 4};
    TreeNode* root = sortedArrayToBST(nums);
    inorder(root);
    std::cout<<std::endl;

    system("pause");
    return 0;
}

