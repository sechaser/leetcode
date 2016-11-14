#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iterator>


int removeDuplicates(std::vector<int>& nums)
{
    if(nums.empty())
        return 0;

    std::vector<int>::iterator it = nums.begin() + 1;
    int count = 1;

    while(it != nums.end())
    {
        if(*it == *(it - 1))
        {
            ++ count;
            if(count > 2)
            {
                it = nums.erase(it);
                continue;
            }
        }
        else
            count = 1;
        ++ it;
    }

    return nums.size();
}

int main()
{
    std::vector<int> nums{1, 1, 1, 1, 1, 2,2, 2, 2, 3};
    std::cout<<removeDuplicates(nums)<<std::endl;


    system("pause");
    return 0;
}

