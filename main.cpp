#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct UndirectedGraphNode
{
    int label;
    std::vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int x): label(x) {}
};


int main()
{
    UndirectedGraphNode a(0);
    UndirectedGraphNode b(1);
    UndirectedGraphNode c(2);

    a.neighbors.push_back(&b);
    a.neighbors.push_back(&c);

    b.neighbors.push_back(&c);
    c.neighbors.push_back(&c);

    system("pause");
    return 0;
}

