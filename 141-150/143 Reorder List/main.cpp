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
    void reorderList(ListNode* head) {
        int n = 0;
        ListNode *p = head, *q, *r, *s;
        while (p != NULL) {
            n++;
            p = p->next;
        }
        if (n <= 2) {
            return;
        }
        p = head;
        for (int i = 0; i < (n - 1) / 2; ++i) {
            p = p->next;
        }
        r = p->next;
        p->next = NULL;
        s = p = r;
        q = p->next;
        if (q != NULL) {
            while (q->next != NULL) {
                r = q->next;
                q->next = p;
                p = q;
                q = r;
            }
            q->next = p;
            s->next = NULL;
        } else {
            q = p;
        }
        p = head;
        while (p != NULL && q != NULL) {
            r = p->next;
            s = q->next;
            p->next = q;
            p = q->next = r;
            q = s;
        }
    }
};

int main() {
    vector<ListNode*> nodes;
    for (int i = 0; i < 3; ++i) {
        nodes.push_back(new ListNode(i));
    }
    for (int i = 0; i < 2; ++i) {
        nodes[i]->next = nodes[i + 1];
    }
    Solution s;
    ListNode *p = nodes[0];
    s.reorderList(nodes[0]);
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    return 0;
}
