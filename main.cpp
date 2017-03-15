#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <unordered_map>
#include <iterator>

std::vector<std::vector<std::string> > groupAnagrams(std::vector<std::string>& strs)
{
    std::vector<std::vector<std::string> > res;
    if(strs.empty())
        return res;

    std::unordered_map<std::string, std::vector<std::string> > mp;
    for(std::vector<std::vector<std::string> >::size_type i = 0; i != strs.size(); ++ i)
    {
        std::string tmp = strs[i];
        std::sort(tmp.begin(), tmp.end());
        mp[tmp].push_back(strs[i]);
    }

    for(std::unordered_map<std::string, std::vector<std::string> >::iterator it = mp.begin(); it != mp.end(); ++ it)
        res.push_back(it->second);

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

