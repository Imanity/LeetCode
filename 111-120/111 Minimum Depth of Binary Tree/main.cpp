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
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else if (root->left == NULL) {
            return minDepth(root->right) + 1;
        } else if (root->right == NULL) {
            return minDepth(root->left) + 1;
        }
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

int main() {
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(3);
    TreeNode *p4 = new TreeNode(4);
    p1->left = p2;
    p2->left = p3;
    p1->right = p4;
    Solution s;
    cout << s.minDepth(p1) << endl;
    cin.get();
    return 0;
}
