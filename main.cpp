#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

void nextPermutation(std::vector<int>& nums)
{
    std::vector<int>::size_type nums_sz = nums.size();

    if(nums_sz > 1)
    {
        int i;
        bool flag = 0;
        for(i = nums_sz - 1; i >= 1; -- i)
        {
            if(nums[i] <= nums[i - 1])
                continue;
            else
            {
                int minIndex = i;
                int j;
                for(j = i + 1; j != nums_sz; ++ j)
                {
                    if(nums[j] < nums[minIndex] && nums[j] > nums[i - 1])
                        minIndex = j;
                }

                int temp = nums[i - 1];
                nums[i - 1] = nums[minIndex];
                nums[minIndex] = temp;
                std::sort(nums.begin() + i, nums.end());

                flag = 1;
                break;
            }
        }

        if(!flag)
            std::sort(nums.begin(), nums.end());
    }
}


int main()
{
    std::vector<int> nums{3, 2, 1};
    nextPermutation(nums);

    for(std::vector<int>::size_type i = 0; i != nums.size(); ++ i)
        std::cout<<nums[i]<<std::endl;

    system("pause");
    return 0;
}

