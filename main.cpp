#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

//Time limit exceed
//std::vector<std::vector<int> > threeSum(std::vector<int>& nums)
//{
//    std::vector<std::vector<int> > res;
//    if(nums.size() < 3)
//        return res;

//    size_t sz = nums.size();
//    for(std::vector<int>::size_type i = 0; i != sz-2; ++ i)
//    {
//        for(std::vector<int>::size_type j = 1; j != sz-1; ++ j)
//        {
//            for(std::vector<int>::size_type k = 2; k != sz; ++ k)
//            {
//                if((nums[i] + nums[j] + nums[k] == 0) && (i != j) && (j != k) && (i != k))
//                {
//                    std::vector<int> oneres{nums[i], nums[j], nums[k]};
//                    res.push_back(oneres);
//                }
//            }
//        }
//    }

//    for(std::vector<std::vector<int> >::size_type i = 0; i != res.size(); ++ i)
//        std::sort(res[i].begin(), res[i].end());
//    std::sort(res.begin(), res.end());
//    std::vector<std::vector<int> >::iterator end_unique = unique(res.begin(), res.end());
//    res.erase(end_unique, res.end());

//    return res;
//}

//Funtion 1
std::vector<std::vector<int> > threeSum(std::vector<int>& nums)
{
    std::vector<std::vector<int> > res;
    if(nums.size() < 3)
        return res;

    size_t sz = nums.size();
    std::sort(nums.begin(), nums.end());

    for(std::vector<int>::size_type i = 0; i != sz-2; ++ i)
    {
        if(i > 0 && nums[i] == nums[i - 1])
            continue;
        for(std::vector<int>::size_type j = i+1; j != sz-1; ++ j)
        {
            for(std::vector<int>::size_type k = j+1; k != sz; ++ k)
            {
                if(nums[i] + nums[j] + nums[k] == 0)
                {
                    std::vector<int> oneres{nums[i], nums[j], nums[k]};
                    res.push_back(oneres);
                    break;
                }
            }
        }
    }

    //There is no need for the second sorting, if add this time limit exceed.
    //Delete this this function will pass.
//    std::sort(res.begin(), res.end());

    std::vector<std::vector<int> >::iterator it = std::unique(res.begin(), res.end());
    res.erase(it, res.end());

    return res;
}

//Funtion 2
//std::vector<std::vector<int> > threeSum(std::vector<int>& nums)
//{
//    std::vector<std::vector<int> > res;
//    if(nums.size() < 3)
//        return res;

//    size_t sz = nums.size();
//    std::sort(nums.begin(), nums.end());

//    int target, head, tail;
//    for(std::vector<std::vector<int> >::size_type i = 0; i != sz-2; ++ i)
//    {
//        if(i > 0 && nums[i] == nums[i-1])
//            continue;

//        target = (-nums[i]);
//        head   = i + 1;
//        tail   = sz - 1;
//        while(head < tail)
//        {
//            int tmp = nums[head] + nums[tail];
//            if(tmp < target)
//                ++ head;
//            else if(tmp > target)
//                -- tail;
//            else
//            {
//                res.push_back(std::vector<int>{nums[i], nums[head], nums[tail]});
//                int k = head + 1;
//                while(k < tail && nums[k] == nums[head])
//                    ++ k;
//                head = k ;

//                k = tail - 1;
//                while(k > head && nums[k] == nums[tail])
//                    -- k;
//                tail = k;
//            }
//        }
//    }

//    return res;
//}

int main()
{
    std::vector<int> nums{-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int> > res = threeSum(nums);

    for(std::vector<std::vector<int> >::size_type i = 0; i != res.size(); ++ i)
    {
        for(std::vector<int>::size_type j = 0; j != res[i].size(); ++ j)
            std::cout<<res[i][j]<<" ";
        std::cout<<std::endl;
    }
    std::cout<<std::endl;

    system("pause");
    return 0;
}

