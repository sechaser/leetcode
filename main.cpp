#include <iostream>
#include <vector>
#include <utility>

int main()
{
    std::vector<int> iv = {2, 7, 11, 15};
    int target = 26;
    std::pair<size_t, size_t> p;

    for(std::vector<int>::size_type i = 0; i != iv.size(); ++ i)
    {
        for(std::vector<int>::size_type j = i + 1; j != iv.size(); ++ j)
        {
            if(iv[i] + iv[j] == target)
            {
                p.first  = i;
                p.second = j;
            }
        }
    }
    std::cout<<p.first<<" "<<p.second<<std::endl;

    return 0;
}

