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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);
        for (int i = 0; i < left.size(); ++i) {
            res.push_back(left[i]);
        }
        res.push_back(root->val);
        for (int i = 0; i < right.size(); ++i) {
            res.push_back(right[i]);
        }
        return res;
    }
};

int main() {
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(3);
    TreeNode *p4 = new TreeNode(4);
    TreeNode *p5 = new TreeNode(5);
    TreeNode *p6 = new TreeNode(6);
    p1->left = p2;
    p1->right = p3;
    p3->left = p4;
    p3->right = p5;
    p4->right = p6;
    Solution s;
    vector<int> t = s.inorderTraversal(p1);
    for (int i = 0; i < t.size(); ++i) {
        cout << t[i] << " ";
    }
    cout << endl;
    cin.get();
    return 0;
}
