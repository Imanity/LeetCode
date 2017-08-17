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
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        if (root == NULL) {
            return res;
        }
        if (root->left == NULL && root->right == NULL) {
            if (root->val == sum) {
                vector<int> single;
                single.push_back(sum);
                res.push_back(single);
            }
            return res;
        }
        vector<vector<int> > l = pathSum(root->left, sum - root->val);
        vector<vector<int> > r = pathSum(root->right, sum - root->val);
        for (int i = 0; i < l.size(); ++i) {
            l[i].insert(l[i].begin(), root->val);
            res.push_back(l[i]);
        }
        for (int i = 0; i < r.size(); ++i) {
            r[i].insert(r[i].begin(), root->val);
            res.push_back(r[i]);
        }
        return res;
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
    vector<vector<int> > res = s.pathSum(p1, 6);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cin.get();
    return 0;
}
