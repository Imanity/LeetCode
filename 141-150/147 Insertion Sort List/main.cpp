#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *sorted_head = new ListNode(INT_MIN);
        ListNode *current = head;
        while (current != NULL) {
            ListNode *next_current = current->next;
            ListNode *p = sorted_head;
            while (p->next != NULL && p->next->val <= current->val) {
                p = p->next;
            }
            ListNode *q = p->next;
            p->next = current;
            current->next = q;
            current = next_current;
        }
        return sorted_head->next;
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
    ListNode *p = s.insertionSortList(nodes[0]);
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    return 0;
}
