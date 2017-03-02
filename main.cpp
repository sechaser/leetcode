#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_set>
#include <queue>

//int ladderLength(std::string beginWord, std::string endWord, std::unordered_set<std::string>& wordList)
//{
//    std::queue<std::string> Q;
//    Q.push(beginWord);
//    Q.push("");

//    int res = 1;
//    while(!Q.empty())
//    {
//        std::string str = Q.front();
//        Q.pop();

//        if(str != "")
//        {
//            int strLen = str.length();
//            for(int i = 0; i != strLen; ++ i)
//            {
//                char tmp = str[i];         //Store the char going to be substituted.
//                for(char c = 'a'; c <= 'z'; ++ c)
//                {
//                    if(c == tmp)
//                        continue;
//                    str[i] = c;

//                    if(str == endWord)
//                        return res + 1;

//                    if(wordList.find(str) != wordList.end())
//                    {
//                        Q.push(str);
//                        wordList.erase(str);
//                    }
//                }

//                str[i] = tmp;              //Recover the char
//            }
//        }
//        else if(!Q.empty())
//        {
//            ++ res;
//            Q.push("");
//        }
//    }

//    return 0;
//}


int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
    if(wordList.empty())
        return 0;

    int res = 1;
    std::queue<std::string> q;
    q.push(beginWord);
    q.push("");

    while(!q.empty())
    {
        std::string tmp = q.front();
        q.pop();

        if(!tmp.empty())
        {
            for(int i = 0; i != tmp.size(); ++ i)
            {
                char ch = tmp[i];
                for(char j = 'a'; j <= 'z'; ++ j)
                {
                    if(ch == j)
                        continue;
                    tmp[i] = j;

                    if(tmp == endWord)
                        return res + 1;

                    if(wordList.empty())
                        return 0;
                    std::vector<std::string>::iterator it = wordList.begin();
                    while(it != wordList.end())
                    {
                        if(*it == tmp)
                        {
                            it = wordList.erase(it);
                            q.push(tmp);
                            break;
                        }
                        else
                            ++ it;
                    }
                }
                tmp[i] = ch;
            }
        }
        else
        {
            if(!q.empty())
            {
                ++ res;
                q.push("");
            }
        }
    }

    return 0;
}

int main()
{
    std::string beginWord = "hit";
    std::string endWord   = "cog";
    std::vector<std::string> wordList{"hot", "hog"};

    std::cout<<ladderLength(beginWord, endWord, wordList)<<std::endl;

    system("pause");
    return 0;
}

