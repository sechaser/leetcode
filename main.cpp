#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_set>
#include <queue>

int ladderLength(std::string beginWord, std::string endWord, std::unordered_set<std::string>& wordList)
{
    std::queue<std::string> Q;
    Q.push(beginWord);
    Q.push("");

    int res = 1;
    while(!Q.empty())
    {
        std::string str = Q.front();
        Q.pop();

        if(str != "")
        {
            int strLen = str.length();
            for(int i = 0; i != strLen; ++ i)
            {
                char tmp = str[i];         //Store the char going to be substituted.
                for(char c = 'a'; c <= 'z'; ++ c)
                {
                    if(c == tmp)
                        continue;
                    str[i] = c;

                    if(str == endWord)
                        return res + 1;

                    if(wordList.find(str) != wordList.end())
                    {
                        Q.push(str);
                        wordList.erase(str);
                    }
                }

                str[i] = tmp;              //Recover the char
            }
        }
        else if(!Q.empty())
        {
            ++ res;
            Q.push("");
        }
    }

    return 0;
}

int main()
{
    std::string beginWord = "hit";
    std::string endWord   = "cog";
    std::unordered_set<std::string> wordList({"hot", "dot", "dog", "lot", "log"});

    std::cout<<ladderLength(beginWord, endWord, wordList)<<std::endl;

    system("pause");
    return 0;
}

