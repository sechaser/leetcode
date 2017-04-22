#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

//void rotate(std::vector<int>& nums, int k)
//{
//    if(k == 0)
//        return;

//    int sz = nums.size();
//    k = k % sz;
//    std::vector<int> res;
//    for(int i = sz-k; i < sz; ++ i)
//        res.push_back(nums[i]);

//    for(int i = 0; i < sz-k; ++ i)
//        res.push_back(nums[i]);

//    nums = res;
//}

void rotate(std::vector<int>& nums, int k)
{
    if(!k)
        return;

    int sz = nums.size();
    k = k % sz;

    std::vector<int> temp(nums.end() - k, nums.end());
    nums.erase(nums.end()- k, nums.end());
    nums.insert(nums.begin(), temp.begin(), temp.end());
}


int main()
{
    std::vector<int> nums{1, 2, 3};
    rotate(nums, 1);

    for(int i = 0 ; i < nums.size(); ++ i)
        std::cout<<nums[i]<<" ";
    std::cout<<std::endl;

    system("pause");
    return 0;
}

