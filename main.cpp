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

vector<int> postorderTraversal(TreeNode* root) {
    std::stack<TreeNode*> stk;
    std::vector<int> res;
    TreeNode* pre = NULL;

    while(root || !stk.empty())
    {
        if(root)
        {
            stk.push(root);
            root = root->left;
        }
        else
        {
            TreeNode* topNode = stk.top();
            if(topNode->right != NULL && pre != topNode->right)
                root = topNode->right;
            else
            {
                stk.pop();
                res.push_back(topNode->val);
                pre = topNode;
            }
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

    std::vector<int> res = inorderTraversal(root);

    for(std::vector<int>::size_type i = 0; i != res.size(); ++ i)
        std::cout<<std::setw(4)<<res[i];
    std::cout<<std::endl;

    system("pause");
    return 0;
}

