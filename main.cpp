#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>


int leftHeight(std::vector<int>& height, int index);
int rightHeight(std::vector<int>& height, int index);

//*******************************************time:O(n^2) space:O(1)*********************************************
//int trap(std::vector<int> &height)
//{
//    if(height.size() <= 2)
//        return 0;

//    size_t height_sz = height.size();
//    int water = 0;

//    //The begin bar and the end bar can be ignored.
//    for(int i = 1; i != height_sz - 1; ++ i)
//    {
//        int left  = leftHeight(height, i);
//        int right = rightHeight(height, i);

//        int minHeight = std::min(left, right);

//        if(minHeight > height[i])
//            water += (minHeight - height[i]);
//    }

//    return water;
//}


//int leftHeight(std::vector<int>& height, int index)
//{
//    int maxHeight = 0;
//    for(int i = 0; i != index; ++ i)
//    {
//        if(height[i] > maxHeight)
//            maxHeight = height[i];
//    }

//    return maxHeight;
//}


//int rightHeight(std::vector<int>& height, int index)
//{
//    int maxHeight = 0;
//    for(int i = height.size() - 1; i > index; -- i)
//    {
//        if(height[i] > maxHeight)
//            maxHeight = height[i];
//    }

//    return maxHeight;
//}

//**************************************************time:O(2n) space:O(2n)***********************************************
//int trap(std::vector<int>& height)
//{
//    if(height.size() <= 2)
//        return 0;

//    size_t height_sz = height.size();
//    std::vector<int> left(height_sz, 0);
//    std::vector<int> right(height_sz, 0);

//    for(size_t i = 1; i != height_sz; ++ i)
//        left[i] = std::max(height[i-1], left[i-1]);

//    int water = 0;
//    for(int i = (height_sz -2); i >= 0; -- i)
//    {
//        right[i] = std::max(right[i+1], height[i+1]);
//        int minHeight = std::min(left[i], right[i]);

//        if(minHeight > height[i])
//            water += (minHeight - height[i]);
//    }

//    return water;
//}


//*************************************************time:O(n) space(1)*************************************
int trap(std::vector<int>& height)
{
    if(height.size() <= 2)
        return 0;

    size_t height_sz = height.size();
    int l = 0, r = height_sz - 1;

    int water = 0;
    while(l < r)
    {
        int minHeight = std::min(height[l], height[r]);

        if(minHeight == height[l])
        {
            ++ l;
            while(l < r && height[l] < minHeight)
            {
                water += (minHeight - height[l]);
                ++ l;
            }
        }
        else
        {
            -- r;
            while(l < r && height[r] < minHeight)
            {
                water += (minHeight - height[r]);
                -- r;
            }
        }
    }

    return water;
}

int main()
{
    std::vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int res = trap(height);
    std::cout<<res<<std::endl;

    system("pause");
    return 0;
}

