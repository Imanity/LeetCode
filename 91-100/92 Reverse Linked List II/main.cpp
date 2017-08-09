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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL) {
            return head;
        }
        ListNode *newHead = new ListNode(0), *p = newHead, *q = head;
        newHead->next = head;
        for (int i = 0; i < m - 1; ++i) {
            p = p->next;
            q = q->next;
        }
        ListNode *left = p, *right = q;
        p = q;
        q = q->next;
        for (int i = m; i < n; ++i) {
            ListNode *tmp = q->next;
            q->next = p;
            p = q;
            q = tmp;
        }
        left->next = p;
        right->next = q;
        return newHead->next;
    }
};

int main() {
    int nums[] = { 1, 2, 3, 4, 5 };
    ListNode *head = new ListNode(1), *p = head;
    for (int i = 1; i < 5; ++i) {
        ListNode *q = new ListNode(nums[i]);
        p->next = q;
        p = q;
    }
    Solution s;
    head = s.reverseBetween(head, 2, 5);
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    cin.get();
    return 0;
}
