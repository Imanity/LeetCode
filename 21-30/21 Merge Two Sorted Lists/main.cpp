#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        } else {
            if(l1->val < l2->val) {
                l1->next = mergeTwoLists(l1->next, l2);
                return l1;
            } else {
                l2->next = mergeTwoLists(l1, l2->next);
                return l2;
            }
        }
    }
};

int main() {
    int list1[] = { 1, 2, 3, 4, 5 };
    int list2[] = { 6, 7, 8, 9, 10, 11 };
    ListNode *p = new ListNode(list1[0]), *head = p;
    for(int i = 0; i < 4; ++i) {
        p->next = new ListNode(list1[i + 1]);
        p = p->next;
    }
    ListNode *q = new ListNode(list2[0]), *head1 = q;
    for(int i = 0; i < 5; ++i) {
        q->next = new ListNode(list2[i + 1]);
        q = q->next;
    }
    Solution s;
    head = s.mergeTwoLists(head, head1);
    while(head != NULL) {
        cout << head->val << "\t";
        head = head->next;
    }
    cin.get();
    return 0;
}
