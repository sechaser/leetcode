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



int numTrees(int n)
{
    std::vector<int> res(n+1, 0);
    res[0] = 1;

    for(int i = 1; i <= n; ++ i)
    {
        for(int j = 0; j < i; ++ j)
            res[i] = res[i] + res[j] * res[i-1-j];
    }

    return res[n];
}

int main()
{
    std::cout<<numTrees(11)<<std::endl;

    system("pause");
    return 0;
}

