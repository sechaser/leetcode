#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iterator>

//int removeDuplicates(std::vector<int>& nums)
//{
//    std::vector<int>::iterator it = std::unique(nums.begin(), nums.end());

//    return (it-nums.begin());
//}

int removeDuplicates(std::vector<int>& nums)
{
    if(nums.size() <= 1)
        return nums.size();

    std::vector<int>::iterator it = nums.begin() + 1;
    while(it != nums.end())
    {
        if(*it == *(it - 1))
            it = nums.erase(it);
        else
            ++ it;
    }

    return nums.size();
}

int main()
{
    std::vector<int> iv{1, 1, 1, 2, 3, 4, 5, 5};
    int res = removeDuplicates(iv);

    std::cout<<res<<std::endl;

    system("pause");
    return 0;
}

