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
    int sumNumbers(TreeNode* root) {
        traverseTree(root);
        return getSum(root);
    }
    void traverseTree(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        if (root->left) {
            root->left->val += root->val * 10;
            traverseTree(root->left);
        }
        if (root->right) {
            root->right->val += root->val * 10;
            traverseTree(root->right);
        }
    }
    int getSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL && root->right == NULL) {
            return root->val;
        }
        int tmp = 0;
        if (root->left != NULL) {
            tmp += getSum(root->left);
        }
        if (root->right != NULL) {
            tmp += getSum(root->right);
        }
        return tmp;
    }
};

int main() {
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(3);
    p1->left = p2;
    p1->right = p3;
    Solution s;
    cout << s.sumNumbers(p1) << endl;
    cin.get();
    return 0;
}
