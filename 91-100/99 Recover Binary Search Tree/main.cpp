#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *first, *second, *prev;
    Solution() {
        first = NULL;
        second = NULL;
        prev = new TreeNode(INT_MIN);
    }
    void recoverTree(TreeNode* root) {
        traverse(root);
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
    void traverse(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        traverse(root->left);
        if (first == NULL && prev->val >= root->val) {
            first = prev;
        }
        if (first != NULL && prev->val >= root->val) {
            second = root;
        }
        prev = root;
        traverse(root->right);
    }
};

int main() {
    TreeNode *p1 = new TreeNode(2);
    TreeNode *p2 = new TreeNode(3);
    TreeNode *p3 = new TreeNode(4);
    TreeNode *p4 = new TreeNode(1);
    TreeNode *p5 = new TreeNode(5);
    TreeNode *p6 = new TreeNode(6);
    p1->left = p2;
    p1->right = p3;
    p3->left = p4;
    p3->right = p5;
    p5->right = p6;
    Solution s;
    s.recoverTree(p1);
    cin.get();
    return 0;
}
