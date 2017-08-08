#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) {
            return head;
        }
        ListNode *p = head, *little = NULL, *large = NULL, *littleHead = NULL, *largeHead = NULL;
        while (p != NULL) {
            if (p->val >= x) {
                if (large == NULL) {
                    largeHead = large = p;
                } else {
                    large->next = p;
                    large = large->next;
                }
            } else {
                if (little == NULL) {
                    littleHead = little = p;
                } else {
                    little->next = p;
                    little = little->next;
                }
            }
            p = p->next;
        }
        if (little != NULL) {
            little->next = largeHead;
        }
        if (large != NULL) {
            large->next = NULL;
        }
        if (littleHead == NULL) {
            return largeHead;
        }
        return littleHead;
    }
};

int main() {
    int num[] = { 1, 4, 3, 2, 5, 2 };
    ListNode *head = new ListNode(1), *p = head;
    for (int i = 1; i < 6; ++i) {
        p->next = new ListNode(num[i]);
        p = p->next;
    }
    Solution s;
    head = s.partition(head, 8);
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cin.get();
    return 0;
}
