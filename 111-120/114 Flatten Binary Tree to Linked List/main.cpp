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
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        flatten(root->left);
        flatten(root->right);
        if (root->left != NULL) {
            TreeNode *q = root->right;
            root->right = root->left;
            TreeNode *p = root->right;
            while (p->right != NULL) {
                p = p->right;
            }
            p->right = q;
            root->left = NULL;
        }
    }
};

int main() {
    TreeNode *p[6];
    for (int i = 0; i < 6; ++i) {
        p[i] = new TreeNode(i + 1);
    }
    p[0]->left = p[1];
    p[0]->right = p[4];
    p[1]->left = p[2];
    p[1]->right = p[3];
    p[4]->right = p[5];
    Solution s;
    s.flatten(p[0]);
    cout << p[0]->val << " " << p[0]->right->val << endl;
    cin.get();
    return 0;
}
