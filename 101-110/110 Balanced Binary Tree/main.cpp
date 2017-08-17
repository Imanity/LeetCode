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
    bool isBalanced(TreeNode* root) {
        int h;
        return checkBalance(root, h);
    }
    bool checkBalance(TreeNode* root, int &h) {
        if (root == NULL) {
            h = 0;
            return true;
        }
        int leftH = 0;
        int rightH = 0;
        bool l = checkBalance(root->left, leftH);
        bool r = checkBalance(root->right, rightH);
        h = max(leftH, rightH) + 1;

        if (!l || !r || abs(leftH - rightH) > 1) {
            return false;
        }
        return true;
    }
};

int main() {
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(3);
    p1->left = p2;
    p2->left = p3;
    Solution s;
    cout << s.isBalanced(p1) << endl;
    cin.get();
    return 0;
}
