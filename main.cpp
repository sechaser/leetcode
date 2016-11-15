#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stack>

int maximalRectangle(std::vector<std::vector<char> >& matrix)
{
    if(matrix.empty())
        return 0;

    for(int i = 0; i != matrix.size(); ++ i)
        matrix[i].push_back('*');

    int row = matrix.size(), col = matrix[0].size();
    std::vector<int> heights(col, 0);
    int area = 0;

    for(int i = 0; i != row; ++ i)
    {
        std::stack<int> stk;

        for(int j = 0; j != col; ++ j)
        {
            if(matrix[i][j] == '1')
                heights[j] += 1;
            else
                heights[j] = 0;
        }

        int j = 0;
        while(j != col)
        {
            if(stk.empty() || heights[j] >= heights[stk.top()])
                stk.push(j++);
            else
            {
                int h = heights[stk.top()];
                stk.pop();

                int w = stk.empty() ? j : j - stk.top() - 1;
                area = std::max(area, h * w);
            }
        }
    }

    return area;
}

int main()
{
    std::vector<std::vector<char> > matrix{std::vector<char>{'1','0','1','0','0'}, std::vector<char>{'1','0','1','1','1'},
                                          std::vector<char>{'1','1','0','0','0'}, std::vector<char>{'1','0','1','1','1'}};

    std::cout<<maximalRectangle(matrix)<<std::endl;

    system("pause");
    return 0;
}

