#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) {
            if (p == NULL && q == NULL) {
                return true;
            }
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
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
    cout << s.isSameTree(p1, p1) << endl;
    cin.get();
    return 0;
}
