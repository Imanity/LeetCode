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
    vector<TreeNode*> generateTrees(int n) {
        return genTreesWithBorder(1, n + 1);
    }
    vector<TreeNode*> genTreesWithBorder(int min, int max) {
        vector<TreeNode*> res;
        if (min >= max) {
            return res;
        }
        for (int i = min; i < max; ++i) {
            vector<TreeNode*> left = genTreesWithBorder(min, i);
            vector<TreeNode*> right = genTreesWithBorder(i + 1, max);
            if (!left.size() && !right.size()) {
                TreeNode *root = new TreeNode(i);
                res.push_back(root);
            } else if (!left.size()) {
                for (int j = 0; j < right.size(); ++j) {
                    TreeNode *root = new TreeNode(i);
                    root->right = right[j];
                    res.push_back(root);
                }
            } else if (!right.size()) {
                for (int j = 0; j < left.size(); ++j) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left[j];
                    res.push_back(root);
                }
            } else {
                for (int j = 0; j < left.size(); ++j) {
                    for (int k = 0; k < right.size(); ++k) {
                        TreeNode *root = new TreeNode(i);
                        root->left = left[j];
                        root->right = right[k];
                        res.push_back(root);
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<TreeNode*> t = s.generateTrees(3);
    for (int i = 0; i < t.size(); ++i) {
        cout << t[i]->val << endl;
        //cout << t[i]->val << " " << t[i]->left->val << " " << t[i]->right->val << endl;
    }
    cin.get();
    return 0;
}
