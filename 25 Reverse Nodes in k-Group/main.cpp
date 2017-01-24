#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) {
            return head;
        }
        int i = 0;
        ListNode *p = head, *q = p->next, *r = p, *last, *newHead = NULL;
        for(int i = 0; i < k - 1; ++i) {
            r = r->next;
            if(r == NULL) {
                return head;
            }
        }
        if(k == 1) {
            return head;
        }
        p->next = NULL;
        while(q != NULL) {
            if (i == 0) {
                last = p;
                p->next = NULL;
            }
            ++i;
            r = q->next;
            q->next = p;
            p = q;
            q = r;
            if (i == k - 1) {
                i = 0;
                r = q;
                if(newHead == NULL) {
                    newHead = p;
                }
                for(int j = 0; j < k - 1 && r != NULL; ++j) {
                    r = r->next;
                }
                if(r == NULL) {
                    last->next = q;
                    break;
                } else {
                    last->next = r;
                }
                p = q;
                q = q->next;
            }
        }
        return newHead;
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
    head = s.reverseKGroup(head, 8);
    while(head != NULL) {
        cout << head->val << "\t";
        head = head->next;
    }
    cin.get();
    return 0;
}
