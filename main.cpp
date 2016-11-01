#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <unordered_map>
#include <iterator>

//Time:O(n), space:O(n)
//std::vector<std::vector<std::string> > groupAnagrams(std::vector<std::string>& strs)
//{
//    std::vector<std::vector<std::string> > res;
//    size_t strs_sz = strs.size();
//    if(strs_sz < 2)
//    {
//        res.push_back(strs);
//        return res;
//    }

//    std::vector<std::pair<int, std::string> > temp;
//    for(std::vector<std::string>::size_type i = 0; i != strs_sz; ++ i)
//        temp.push_back(std::pair<int, std::string>(i, strs[i]));

//    for(std::vector<std::pair<int, std::string> >::size_type i = 0; i != temp.size(); ++ i)
//        std::sort(temp[i].second.begin(), temp[i].second.end());

//    std::sort(temp.begin(), temp.end(), [](const std::pair<int, std::string>& lhs, const std::pair<int, std::string>& rhs){
//        return lhs.second < rhs.second;
//    });

//    std::string str;
//    for(std::vector<std::pair<int, std::string> >::size_type i = 0; i != temp.size(); ++ i)
//    {
//        if(i == 0)
//        {
//            res.push_back(std::vector<std::string>{strs[temp[0].first]});
//            str = temp[0].second;
//        }
//        else
//        {
//            if(temp[i].second == str)
//                res[res.size() - 1].push_back(strs[temp[i].first]);
//            else
//            {
//                str = temp[i].second;
//                res.push_back(std::vector<std::string>{strs[temp[i].first]});
//            }
//        }
//    }

//    return res;
//}

std::vector<std::vector<std::string> > groupAnagrams(std::vector<std::string>& strs)
{
    std::unordered_map<std::string, std::vector<int> > hashTable;

    std::string str;
    for(std::vector<std::string>::size_type i = 0; i != strs.size(); ++ i)
    {
        str = strs[i];
        std::sort(str.begin(), str.end());
        hashTable[str].push_back(i);
    }

    std::vector<std::vector<std::string> > res;
    for(std::unordered_map<std::string, std::vector<int> >::iterator it = hashTable.begin(); it != hashTable.end(); ++ it)
    {
        std::vector<std::string> tmp;
        for(std::vector<int>::size_type i = 0; i != it->second.size(); ++ i)
            tmp.push_back(strs[it->second[i]]);
        res.push_back(tmp);
    }

    return res;
}


int main()
{
    std::vector<std::string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string> > res = groupAnagrams(strs);

    std::cout<<res.size()<<std::endl;
    for(std::vector<std::vector<std::string> >::size_type i = 0; i != res.size(); ++ i)
    {
        for(std::vector<std::string>::size_type j = 0; j != res[i].size(); ++ j)
            std::cout<<std::setw(4)<<res[i][j];
        std::cout<<std::endl;
    }

    system("pause");
    return 0;
}

