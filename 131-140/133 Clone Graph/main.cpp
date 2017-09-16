#include <iostream>
#include <vector>
#include <tr1/unordered_map>

using namespace std;
using namespace std::tr1;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    unordered_map<int, UndirectedGraphNode*> hmap;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) {
            return NULL;
        }
        UndirectedGraphNode *p = new UndirectedGraphNode(node->label);
        hmap[node->label] = p;
        for (int i = 0; i < node->neighbors.size(); ++i) {
            int label = node->neighbors[i]->label;
            if (hmap[label] != NULL) {
                p->neighbors.push_back(hmap[label]);
            } else {
                UndirectedGraphNode *q = cloneGraph(node->neighbors[i]);
                p->neighbors.push_back(q);
            }
        }
        return p;
    }
};

int main() {
    UndirectedGraphNode *p = new UndirectedGraphNode(1);
    UndirectedGraphNode *q = new UndirectedGraphNode(2);
    UndirectedGraphNode *r = new UndirectedGraphNode(3);
    p->neighbors.push_back(q);
    p->neighbors.push_back(r);
    Solution s;
    UndirectedGraphNode *g = s.cloneGraph(p);
    cout << g->label << " " << g->neighbors[0]->label << " " << g->neighbors[1]->label << endl;
    cin.get();
    return 0;
}
