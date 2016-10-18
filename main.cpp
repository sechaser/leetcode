#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iterator>

int removeElement(std::vector<int>& nums, int val)
{
    if(nums.size() == 0)
        return 0;

    std::sort(nums.begin(), nums.end());
    std::vector<int>::iterator it = nums.begin();

    while(it != nums.end())
    {
        if(*it == val)
            it = nums.erase(it);
        else
            ++ it;
    }
    return nums.size();
}

int main()
{
    std::vector<int> nums{2, 2,1, 3, 54, 5};
    int res = removeElement(nums, 10);

    std::cout<<res<<std::endl;

    system("pause");
    return 0;
}

