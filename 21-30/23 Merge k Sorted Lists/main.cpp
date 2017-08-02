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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) {
            return NULL;
        }
        for(int i = 1; i < lists.size(); ++i) {
            lists[0] = mergeTwoLists(lists[0], lists[i]);
        }
        return lists[0];
    }
};

int main() {
    int list[3][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {-4, -3, -2, -1, 0}};
    vector<ListNode*> lists;
    for(int i = 0; i < 3; ++i) {
        ListNode *p = new ListNode(list[i][0]), *head = p;
        for(int j = 0; j < 4; ++j) {
            p->next = new ListNode(list[i][j + 1]);
            p = p->next;
        }
        lists.push_back(head);
    }
    Solution s;
    ListNode *head = s.mergeKLists(lists);
    while(head != NULL) {
        cout << head->val << "\t";
        head = head->next;
    }
    cin.get();
    return 0;
}
