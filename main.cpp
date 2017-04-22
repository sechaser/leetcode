#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_set>

bool containsDuplicate(std::vector<int>& nums)
{
    std::unordered_set<int> st;
    for(int i = 0; i < nums.size(); ++ i)
    {
        if(st.count(nums[i]))
            return true;
        st.insert(nums[i]);
    }

    return false;
}

int main()
{
    std::vector<int> nums{1,23};
    std::cout<<containsDuplicate(nums)<<std::endl;


    system("pause");
    return 0;
}

