#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL) {
            TreeNode *root = new TreeNode(head->val);
            return root;
        }
        ListNode *p = head;
        int num = 0;
        while (p != NULL) {
            p = p->next;
            ++num;
        }
        int pos = num / 2;
        p = head;
        for (int i = 0; i < pos - 1; ++i) {
            p = p->next;
        }
        ListNode *q = p->next;
        p->next = NULL;
        TreeNode *root = new TreeNode(q->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(q->next);
        return root;
    }
};

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    ListNode *head = new ListNode(1), *p = head;
    for (int i = 1; i < 5; ++i) {
        ListNode *q = new ListNode(arr[i]);
        p->next = q;
        p = q;
    }
    Solution s;
    TreeNode *t = s.sortedListToBST(head);
    cout << t->val << endl;
    cin.get();
    return 0;
}
