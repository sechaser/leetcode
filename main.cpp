#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
//void swap(std::vector<int>& nums, int low, int high)
//{
//    int temp   = nums[low];
//    nums[low]  = nums[high];
//    nums[high] = temp;
//}

//int partition(std::vector<int>& nums, int low, int high)
//{
//    int value = nums[low];
//    while(low < high)
//    {
//        while((low < high) && (nums[high] >= value))
//            -- high;
//        swap(nums, low, high);

//        while((low < high) && (nums[low] <= value))
//            ++ low;
//        swap(nums, low, high);
//    }

//    return low;
//}

//void quickSort(std::vector<int>& nums, int low, int high)
//{
//    if(low < high)
//    {
//        int location = partition(nums, low, high);
//        quickSort(nums, low, location - 1);
//        quickSort(nums, location + 1, high);
//    }
//}

//void sortColors(std::vector<int>& nums)
//{
//    if(nums.empty())
//        return;

//    int sz = nums.size();
//    int low = 0, high = sz - 1;

//    quickSort(nums, low, high);
//}


void sortColors(std::vector<int>& nums)
{
    int left = 0, right = nums.size() - 1;
    int i = 0;

    while(i <= right)
    {
        if(nums[i] == 0)
            std::swap(nums[i++], nums[left++]);
        else if(nums[i] == 1)
            ++ i;
        else
            std::swap(nums[i], nums[right--]);
    }
}

int main()
{
    std::vector<int> nums{1,0};
    sortColors(nums);

    for(std::vector<int>::size_type i = 0; i != nums.size(); ++ i)
        std::cout<<std::setw(4)<<nums[i]<<std::endl;

    system("pause");
    return 0;
}

