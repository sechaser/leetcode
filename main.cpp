#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

void helper(std::string& oneres, std::vector<std::string>& res, int left, int right);

std::vector<std::string> generateParenthesis(int n)
{
    std::string oneres;
    std::vector<std::string> res;

    helper(oneres, res, n, n);

    return res;
}

void helper(std::string& oneres, std::vector<std::string>& res, int left, int right)
{
    if(left > right)
        return;

    if(left == 0 && right == 0)
    {
        res.push_back(oneres);
        return;
    }

    if(left > 0)
    {
        oneres.push_back('(');
        helper(oneres, res, left - 1, right);
        oneres.pop_back();
    }

    if(right > 0)
    {
        oneres.push_back(')');
        helper(oneres, res, left, right - 1);
        oneres.pop_back();
    }

}

int main()
{
    std::vector<std::string> res = generateParenthesis(3);
    for(std::vector<std::string>::size_type i = 0; i != res.size(); ++ i)
        std::cout<<res[i]<<std::endl;

    system("pause");
    return 0;
}

