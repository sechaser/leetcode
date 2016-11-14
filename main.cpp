#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stack>

int largestRectangleArea(std::vector<int>& heights)
{
    if(heights.empty())
        return 0;


    heights.push_back(INT_MIN);
    int area = 0;


    std::stack<int> stk;
    std::vector<int>::size_type i = 0;
    int h, w;

    while(i != heights.size())
    {
        if(stk.empty() || heights[i] >= heights[stk.top()])
            stk.push(i++);
        else
        {
            h = heights[stk.top()];
            stk.pop();

            w = stk.empty() ? i : i - stk.top() - 1;
            area = std::max(area, h * w);
        }
    }

    return area;
}


int main()
{
    std::vector<int> heights{2,1,5,6,2,3};
    std::cout<<largestRectangleArea(heights)<<std::endl;

    system("pause");
    return 0;
}

