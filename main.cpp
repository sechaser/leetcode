#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_map>

//std::vector<int> findSubstring(std::string s, std::vector<std::string>& words)
//{
//    std::vector<int> res;
//    if(s.empty() || words.empty())
//        return res;

//    size_t word_sz = words.size(), word_length = words[0].size();
//    if(word_sz * word_length > s.size())
//        return res;

//    //Use words vector to build associate container.
//    std::unordered_map<std::string, int> m1;
//    for(auto &e : words)
//        ++ m1[e];

//    for(size_t i = 0; i <= (s.size() - word_sz * word_length); ++ i)
//    {
//        std::unordered_map<std::string, int> m2;
//        int j;

//        for(j = 0; j != word_sz; ++ j)
//        {
//            std::string t = s.substr(i + j * word_length, word_length);
//            if(m1.find(t) == m1.end())
//                break;

//            ++ m2[t];

//            //No repetition
//            if(m2[t] > m1[t])
//                break;
//        }

//        if(j == word_sz)
//            res.push_back(i);
//    }

//    return res;
//}

std::vector<int> findSubstring(std::string s, std::vector<std::string>& words)
{
    std::vector<int> res;
    if(s.empty() || words.empty())
        return res;

    std::string::size_type sz = s.size(), word_length = words[0].size();
    std::vector<std::string>::size_type words_sz = words.size();
    if(words_sz * word_length > sz)
        return res;

    std::unordered_map<std::string, int> m1;
    for(auto &e : words)
        ++ m1[e];

    for(size_t i = 0; i != word_length; ++ i)
    {
        int left = i, count = 0;
        std::unordered_map<std::string, int> m2;

        for(int j = i; j <= sz - word_length; j = j + word_length)
        {
            std::string t = s.substr(j, word_length);

            if(m1.count(t))
            {
                ++ m2[t];
                if(m2[t] <= m1[t])
                    ++ count;
                else
                {
                    while(m2[t] > m1[t])
                    {
                        std::string t1 = s.substr(left, word_length);
                        -- m2[t1];

                        if(m2[t1] < m1[t1])
                            -- count;
                        left = left + word_length;
                    }
                }

                if(count == words_sz)
                {
                    res.push_back(left);
                    -- m2[s.substr(left, word_length)];
                    -- count;
                    left = left + word_length;
                }
            }
            else
            {
                m2.clear();
                count = 0;
                left = j + word_length;
            }
        }
    }

    return res;
}

int main()
{
    std::string s = "a";
    std::vector<std::string> words{"a", "a"};
    std::vector<int> res = findSubstring(s, words);

    for(std::vector<int>::size_type i = 0; i != res.size(); ++ i)
        std::cout<<std::setw(4)<<res[i];
    std::cout<<std::endl;

    system("pause");
    return 0;
}

