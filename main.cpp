#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_map>
#include <queue>

struct UndirectedGraphNode
{
    int label;
    std::vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int x): label(x) {}
};


/* DFS */
//UndirectedGraphNode* solver(UndirectedGraphNode* node, std::unordered_map<int, UndirectedGraphNode*>& track)
//{
//    if(node == NULL)
//        return NULL;

//    if(track.count(node->label))
//        return track[node->label];

//    UndirectedGraphNode* new_node = new UndirectedGraphNode(node->label);
//    new_node->neighbors.resize(node->neighbors.size());
//    track[node->label] = new_node;

//    for(int i = 0; i != node->neighbors.size(); ++ i)
//        new_node->neighbors[i] = solver(node->neighbors[i], track);

//    return new_node;
//}

//UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node)
//{
//    std::unordered_map<int, UndirectedGraphNode*> track;
//    return solver(node, track);
//}

/* BFS */
//UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node)
//{
//    if(node == NULL)
//        return NULL;

//    std::unordered_map<int, UndirectedGraphNode*> mp;
//    UndirectedGraphNode* new_node = new UndirectedGraphNode(node->label);

//    mp[node->label] = new_node;
//    std::queue<UndirectedGraphNode*> toVisit;
//    toVisit.push(node);

//    while(!toVisit.empty())
//    {
//        UndirectedGraphNode* cur = toVisit.front();
//        toVisit.pop();

//        for(UndirectedGraphNode* neigh : cur->neighbors)
//        {
//            if(!mp.count(neigh->label))
//            {
//                UndirectedGraphNode* tmp = new UndirectedGraphNode(neigh->label);
//                mp[neigh->label] = tmp;
//                toVisit.push(neigh);
//            }
//            mp[cur->label]->neighbors.push_back(mp[neigh->label]);
//        }
//    }

//    return new_node;
//}


UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
{
    if(!node)
        return NULL;
    UndirectedGraphNode *p1 = node;
    UndirectedGraphNode *p2 = new UndirectedGraphNode(node->label);
    std::unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> ht;
    std::queue<UndirectedGraphNode*> q;

    q.push(node);
    ht[node] = p2;

    while(!q.empty())
    {
        p1 = q.front();
        p2 = ht[p1];
        q.pop();

        for(int i=0; i<p1->neighbors.size(); i++)
        {
            UndirectedGraphNode *nb = p1->neighbors[i];
            if(ht.count(nb))
                p2->neighbors.push_back(ht[nb]);
            else
            {
                UndirectedGraphNode *temp = new UndirectedGraphNode(nb->label);
                p2->neighbors.push_back(temp);
                ht[nb] = temp;
                q.push(nb);
            }
        }
    }

    return ht[node];
}
int main()
{
    UndirectedGraphNode a(0);
    UndirectedGraphNode b(1);
    UndirectedGraphNode c(2);

    a.neighbors.push_back(&b);
    a.neighbors.push_back(&c);
    b.neighbors.push_back(&c);
    c.neighbors.push_back(&c);

    UndirectedGraphNode* res = cloneGraph(&a);

    system("pause");
    return 0;
}

