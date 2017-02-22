#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_map>

bool checkSubString(std::string s, int beg, std::vector<std::string>& words, std::unordered_map<std::string, int>& ht)
{
    std::unordered_map<std::string, int> tmpHt;

    for(int num = 0; num != words.size(); ++ num)
    {
        std::string str = s.substr(beg + words[0].size() * num, words[0].size());
        ++ tmpHt[str];
    }

    return tmpHt == ht;
}

std::vector<int> findSubstring(std::string s, std::vector<std::string>& words)
{
    std::vector<int> res;
    if(s.empty() || words.empty())
        return res;

    int word_length = words[0].size();
    int words_sz = words.size();

    if(word_length * words_sz > s.size())
        return res;

    std::unordered_map<std::string, int> ht;
    for(int i = 0; i != words_sz; ++ i)
        ++ ht[words[i]];

    int sz = s.size();
    for(std::string::size_type i = 0; i <= (sz - word_length * words_sz); ++ i)
    {
        if(checkSubString(s, i, words, ht))
            res.push_back(i);
    }

    return res;
}

int main()
{
    std::string s = "abac";
    std::vector<std::string> words{"a", "b"};
    std::vector<int> res = findSubstring(s, words);

    for(std::vector<int>::size_type i = 0; i != res.size(); ++ i)
        std::cout<<std::setw(4)<<res[i];
    std::cout<<std::endl;

    system("pause");
    return 0;
}

