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
    ListNode* sortList(ListNode* head) {
        int n = 0;
        ListNode *p = head, *q;
        while (p != NULL) {
            p = p->next;
            n++;
        }
        if (n <= 1) {
            return head;
        }
        p = q = head;
        for (int i = 0; i < n / 2 - 1; ++i) {
            p = p->next;
        }
        q = p->next;
        p->next = NULL;
        p = head;
        p = sortList(p);
        q = sortList(q);
        ListNode *new_head = new ListNode(0), *t = new_head;
        while (p != NULL && q != NULL) {
            if (p->val < q->val) {
                t = t->next = p;
                p = p->next;
            } else {
                t = t->next = q;
                q = q->next;
            }
        }
        while (p != NULL) {
            t = t->next = p;
            p = p->next;
        }
        while (q != NULL) {
            t = t->next = q;
            q = q->next;
        }
        return new_head->next;
    }
};

int main() {
    int val[] = { -1, 5, 3, 4, 0 };
    vector<ListNode*> nodes;
    for (int i = 0; i < 5; ++i) {
        nodes.push_back(new ListNode(val[i]));
    }
    for (int i = 0; i < 4; ++i) {
        nodes[i]->next = nodes[i + 1];
    }
    Solution s;
    ListNode *p = s.sortList(nodes[0]);
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    return 0;
}
