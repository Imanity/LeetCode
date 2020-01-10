#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p = head, *q = head;
        while (p != NULL && q != NULL) {
            p = p->next;
            if (q->next == NULL) {
                return 0;
            }
            q = q->next->next;
            if (p == q) {
                return 1;
            }
        }
        return 0;
    }
};

int main() {
    return 0;
}
