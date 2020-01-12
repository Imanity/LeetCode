#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        stack<TreeNode*> S;
        S.push(root);
        while (!S.empty()) {
            TreeNode* t = S.top();
            res.push_back(t->val);
            S.pop();
            if (t->right != NULL) {
                S.push(t->right);
            }
            if (t->left != NULL) {
                S.push(t->left);
            }
        }
        return res;
    }
};

int main() {
    TreeNode *p = new TreeNode(1);
    TreeNode *q = new TreeNode(2);
    TreeNode *r = new TreeNode(3);
    p->right = q;
    q->left = r;
    Solution s;
    vector<int> res = s.preorderTraversal(p);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
