#include <iostream>
#include <vector>
#include <algorithm>

int maxArea(std::vector<int>& height)
{
    int area = 0;
    int maxArea = 0;
    std::vector<int>::size_type i = 0, j = height.size() - 1;

    while(i < j)
    {
        area = (j - i) * std::min(height[i], height[j]);

        if(height[i] < height[j])
            ++ i;
        else
            -- j;

        if(area > maxArea)
            maxArea = area;
    }

    return maxArea;
}

int main()
{

    return 0;
}

