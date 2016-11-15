#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iterator>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
    nums1.erase(nums1.begin() + m, nums1.end());
    std::vector<int>::iterator it1 = nums1.begin(), it2 = nums2.begin();

    while(m > 0 && n > 0)
    {
        if(*it1 <= *it2)
        {
            ++ it1;
            -- m;
        }
        else
        {
            it1 = nums1.insert(it1, *it2);
            ++ it1;
            ++ it2;
            -- n;
        }
    }

    while(n > 0)
    {
        nums1.push_back(*it2);
        ++ it2;
        -- n;
    }
}

int main()
{
    std::vector<int> nums1{4, 0, 0, 0, 0, 0};
    std::vector<int> nums2{1, 2, 3, 5, 6};

    merge(nums1, 1, nums2, 5);

    for(std::vector<int>::size_type i = 0; i != nums1.size(); ++ i)
        std::cout<<std::setw(4)<<nums1[i];
    std::cout<<std::endl;

    system("pause");
    return 0;
}

