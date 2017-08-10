#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        TreeNode *p;
        bool leftCheck = true, rightCheck = true;
        if (root->left != NULL) {
            p = root->left;
            while (p->right != NULL) {
                p = p->right;
            }
            if (p->val >= root->val) {
                cout << p->val << " " << root->val << endl;
                return false;
            }
            leftCheck = isValidBST(root->left);
        }
        if (root->right != NULL) {
            p = root->right;
            while (p->left != NULL) {
                p = p->left;
            }
            if (p->val <= root->val) {
                return false;
            }
            rightCheck = isValidBST(root->right);
        }
        return leftCheck && rightCheck;
    }
};

int main() {
    TreeNode *p1 = new TreeNode(2);
    TreeNode *p2 = new TreeNode(1);
    TreeNode *p3 = new TreeNode(4);
    TreeNode *p4 = new TreeNode(3);
    TreeNode *p5 = new TreeNode(5);
    TreeNode *p6 = new TreeNode(6);
    p1->left = p2;
    p1->right = p3;
    p3->left = p4;
    p3->right = p5;
    p5->right = p6;
    Solution s;
    cout << s.isValidBST(p1) << endl;
    cin.get();
    return 0;
}
