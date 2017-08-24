#include <iostream>
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
    int maxPathSum(TreeNode* root) {
        int a = maxDoubleSum(root);
        int b = root->left != NULL ? maxPathSum(root->left) : INT_MIN;
        int c = root->right != NULL ? maxPathSum(root->right) : INT_MIN;
        return max(max(a, b), c);
    }
    int maxSingleSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int curr = root->val;
        if (root->left == NULL && root->right == NULL) {
            return curr;
        }
        int left = root->left != NULL ? maxSingleSum(root->left) : INT_MIN;
        int right = root->right != NULL ? maxSingleSum(root->right) : INT_MIN;
        int tmp = max(left, right);
        return (curr + (tmp > 0 ? tmp : 0));
    }
    int maxDoubleSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int curr = root->val;
        int left = root->left != NULL ? maxSingleSum(root->left) : 0;
        int right = root->right != NULL ? maxSingleSum(root->right) : 0;
        return (curr + (left > 0 ? left : 0) + (right > 0 ? right : 0));
    }
};

int main() {
    TreeNode *p1 = new TreeNode(2);
    TreeNode *p2 = new TreeNode(-1);
    p1->left = p2;
    Solution s;
    cout << s.maxPathSum(p1) << endl;
    cin.get();
    return 0;
}
