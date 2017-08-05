#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* prev = new ListNode(0);
        prev->next = head;
        ListNode *p = prev, *q = p->next;
        while (p != NULL) {
            q = p->next;
            while (q != NULL && q->next != NULL && q->val == q->next->val) {
                int tmp = q->val;
                while (q != NULL && q->val == tmp) {
                    q = q->next;
                }
            }
            p->next = q;
            p = p->next;
        }
        return prev->next;
    }
};

int main() {
    int num[] = { 1, 2, 3, 3, 4, 4, 5 };
    ListNode *head, *p;
    head = new ListNode(1);
    p = head;
    for (int i = 1; i < 7; ++i) {
        ListNode *q = new ListNode(num[i]);
        p->next = q;
        p = q;
    }
    Solution s;
    head = s.deleteDuplicates(head);
    p = head;
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    cin.get();
    return 0;
}
