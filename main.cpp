#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <iterator>

//int singleNumber(std::vector<int>& nums)
//{
//    std::map<int, int> mp;

//    for(int i = 0; i != nums.size(); ++ i)
//        ++ mp[nums[i]];

//    for(std::map<int, int>::iterator it = mp.begin(); it != mp.end(); ++ it)
//    {
//        if(it->second == 1)
//            return it->first;
//    }
//}


int singleNumber(std::vector<int>& nums)
{
    int ones = 0, twos = 0, xthrees = 0;

    for(int i = 0; i != nums.size(); ++ i)
    {
        twos |= (ones & nums[i]);
        ones ^= nums[i];
        xthrees = ~(ones & twos);

        ones &= xthrees;
        twos &= xthrees;
    }

    return ones;
}

int main()
{
    std::vector<int> nums{1, 2, 3, 2, 1, 2, 1};
    std::cout<<singleNumber(nums)<<std::endl;

    system("pause");
    return 0;
}

