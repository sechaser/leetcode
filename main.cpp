#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iterator>
#include <unordered_set>
#include <unordered_map>
#include <queue>



typedef std::unordered_set<std::string>::iterator HashIter;

void constructResult(std::unordered_map<std::string, std::vector<std::string> >& prePath, std::vector<std::vector<std::string> >& res,
                     std::vector<std::string>& tmpres, std::string& beginWord, std::string& endWord)
{
    if(beginWord == endWord)
    {
        std::reverse(tmpres.begin(), tmpres.end());
        res.push_back(tmpres);
        std::reverse(tmpres.begin(), tmpres.end());
        return;
    }

    std::vector<std::string>& pre = prePath[endWord];
    for(int i = 0; i != pre.size(); ++ i)
    {
        tmpres.push_back(pre[i]);
        constructResult(prePath, res, tmpres, beginWord, pre[i]);
        tmpres.pop_back();
    }
}

std::vector<std::vector<std::string> > findLadders(std::string beginWord, std::string endWord, std::vector<std::string>& wordList)
{
    std::queue<std::string> Q;
    Q.push(beginWord);
    Q.push("");
    bool hasFound = false;

    std::unordered_map<std::string, std::vector<std::string> > prePath;
    std::unordered_set<std::string> hashTable;

    while(!Q.empty())
    {
        std::string str = Q.front(), strCopy = str;
        Q.pop();

        if(str != "")
        {
            int strLen = str.length();
            for(int i = 0; i != strLen; ++ i)
            {
                char tmp = str[i];
                for(char c = 'a'; c <= 'z'; ++ c)
                {
                    if(c == tmp)
                        continue;
                    str[i] = c;
                    if(str == endWord)
                    {
                        hasFound = true;
                        prePath[endWord].push_back(strCopy);
                        goto END;
                    }

                    if(std::find(wordList.begin(), wordList.end(), str) != wordList.end())
                    {
                        prePath[str].push_back(strCopy);
                        if(hashTable.find(str) == hashTable.end())
                        {
                            Q.push(str);
                            hashTable.insert(str);
                        }
                    }
                }

                str[i] = tmp;
            }
        }
        else if(!Q.empty())
        {
            if(hasFound)
                break;

            std::vector<std::string> tmp;
            for(HashIter it = hashTable.begin(); it != hashTable.end(); ++ it)
                tmp.push_back(*it);
            hashTable.clear();

            for(std::vector<std::string>::size_type i = 0; i != tmp.size(); ++ i)
            {
                std::vector<std::string>::iterator it = wordList.begin();
                while(it != wordList.end())
                {
                    if(*it == tmp[i])
                    {
                        wordList.erase(it);
                        break;
                    }
                    else
                        ++ it;
                }
            }

            Q.push("");
        }
        END: ;
    }

    std::vector<std::vector<std::string> > res;
    if(prePath.find(endWord) == prePath.end())
        return res;

    std::vector<std::string> tmpres;
    tmpres.push_back(endWord);

    constructResult(prePath, res, tmpres, beginWord, endWord);
    return res;
}




int main()
{
    std::string beginWord = "hit", endWord = "cog";
    std::vector<std::string> wordList({"hot", "dot", "dog", "lot", "log"});
    std::vector<std::vector<std::string> > res = findLadders(beginWord, endWord, wordList);
    for(int i = 0; i != res.size(); ++ i)
    {
        for(int j = 0; j != res[i].size(); ++ j)
            std::cout<<res[i][j]<<" ";
        std::cout<<std::endl;
    }


    system("pause");
    return 0;
}

