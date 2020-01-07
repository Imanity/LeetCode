#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *p = head;
        int idx = 0;
        vector<Node*> origin_nodes;
        vector<Node*> nodes;
        while (p != NULL) {
            Node *q = new Node(p->val);
            origin_nodes.push_back(p);
            nodes.push_back(q);
            Node* p_ = p;
            p = p->next;
            p_->next = q;
            idx++;
        }
        for (int i = 0; i < nodes.size(); ++i) {
            nodes[i]->next = i < (nodes.size() - 1) ? nodes[i + 1] : NULL;
            if (origin_nodes[i]->random != NULL) {
                nodes[i]->random = origin_nodes[i]->random->next;
            }
        }
        for (int i = 0; i < origin_nodes.size(); ++i) {
            origin_nodes[i]->next = i < (origin_nodes.size() - 1) ? origin_nodes[i + 1] : NULL;
        }
        if (!nodes.size()) {
            return NULL;
        }
        return nodes[0];
    }
};

int main() {
    return 0;
}
