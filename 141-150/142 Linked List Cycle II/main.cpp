#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *p = head, *q = head;
        while (p != NULL && q != NULL) {
            p = p->next;
            if (q->next == NULL) {
                return NULL;
            }
            q = q->next->next;
            if (p == q) {
                break;
            }
        }
        if (p == NULL || q == NULL) {
            return NULL;
        }
        q = head;
        while (p != q) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};

int main() {
    vector<ListNode*> nodes;
    for (int i = 0; i < 5; ++i) {
        nodes.push_back(new ListNode(i));
    }
    for (int i = 0; i < 4; ++i) {
        nodes[i]->next = nodes[i + 1];
    }
    nodes[4]->next = nodes[2];
    Solution s;
    cout << s.detectCycle(nodes[0])->val << endl;
    return 0;
}
