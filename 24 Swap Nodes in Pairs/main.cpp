#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) {
            return NULL;
        } else if (head->next == NULL) {
            return head;
        }
        ListNode *p = head, *q = p->next, *r;
        head = q;
        while(q->next != NULL && q->next->next != NULL) {
            p->next = q->next->next;
            r = q->next;
            q->next = p;
            p = r;
            q = p->next;
        }
        if(q->next != NULL) {
            p->next = q->next;
        } else {
            p->next = NULL;
        }
        q->next = p;
        return head;
    }
};

int main() {
    int list[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    ListNode *p = new ListNode(list[0]), *head = p;
    for(int i = 0; i < 7; ++i) {
        p->next = new ListNode(list[i + 1]);
        p = p->next;
    }
    Solution s;
    head = s.swapPairs(head);
    while(head != NULL) {
        cout << head->val << "\t";
        head = head->next;
    }
    cin.get();
    return 0;
}
