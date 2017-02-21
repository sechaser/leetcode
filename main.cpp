#include <iostream>
#include <vector>
#include <algorithm>

//int maxArea(std::vector<int>& height)
//{
//    int area = 0;
//    int maxArea = 0;
//    std::vector<int>::size_type i = 0, j = height.size() - 1;

//    while(i < j)
//    {
//        area = (j - i) * std::min(height[i], height[j]);

//        if(height[i] < height[j])
//            ++ i;
//        else
//            -- j;

//        if(area > maxArea)
//            maxArea = area;
//    }

//    return maxArea;
//}


int maxArea(std::vector<int>& height)
{
    int water = 0;
    std::vector<int>::size_type i = 0, j = height.size() - 1;
    int h;

    while(i < j)
    {
        h = std::min(height[i], height[j]);
        water = std::max(water, (j - i) * h);

        while(height[i] <= h && i < j)
            ++ i;
        while(height[j] <= h && i < j)
            -- j;
    }

    return maxArea;
}


int main()
{

    return 0;
}

