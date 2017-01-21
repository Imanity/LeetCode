#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *q = head;
        for(int i = 0; i < n + 1; ++i) {
            if(q == NULL) {
                p = head->next;
                delete(head);
                return p;
            }
            q = q->next;
        }
        while(q != NULL) {
            p = p->next;
            q = q->next;
        }
        q = p->next;
        p->next = p->next->next;
        delete(q);
        return head;
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
    head = s.removeNthFromEnd(head, 5);
    while(head != NULL) {
        cout << head->val << "\t";
        head = head->next;
    }
    cin.get();
    return 0;
}