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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        TreeNode *newTree = symmetric(root);
        return isSameTree(newTree, root);
    }
    TreeNode* symmetric(TreeNode *root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode *newTree = new TreeNode(root->val);
        newTree->left = symmetric(root->right);
        newTree->right = symmetric(root->left);
        return newTree;
    }
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
    TreeNode *p = new TreeNode(1);
    TreeNode *l = new TreeNode(2);
    TreeNode *r = new TreeNode(2);
    p->left = l;
    p->right = r;
    Solution s;
    cout << s.isSymmetric(p) << endl;
    cin.get();
    return 0;
}
