#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) {
            return head;
        }
        ListNode *p = head;
        int n = 1;
        while (p->next != NULL) {
            p = p->next;
            ++n;
        }
        p->next = head;
        k = k % n;
        p = head;
        for (int i = 0; i < n - k - 1; ++i) {
            p = p->next;
        }
        ListNode *q = p->next;
        p->next = NULL;
        return q;
    }
};

int main() {
    int list[] = { 1, 2, 3, 4, 5 };
    ListNode *p = new ListNode(list[0]), *head = p;
    for(int i = 0; i < 4; ++i) {
        p->next = new ListNode(list[i + 1]);
        p = p->next;
    }
    Solution s;
    head = s.rotateRight(head, 6);
    while (head != NULL) {
        cout << head->val << "\t";
        head = head->next;
    }
    cin.get();
    return 0;
}
