#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct NodeWithHeight {
    TreeNode *t;
    int h;
    NodeWithHeight(TreeNode *root, int height) : t(root), h(height) {}
};

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        queue<NodeWithHeight> q;
        if (root == NULL) {
            return res;
        }
        q.push(NodeWithHeight(root, 0));
        vector<int> line;
        while (q.size()) {
            NodeWithHeight p = q.front();
            if (p.h != res.size()) {
                res.push_back(line);
                line.resize(0);
            }
            line.push_back(p.t->val);
            if (p.t->left != NULL) {
                q.push(NodeWithHeight(p.t->left, p.h + 1));
            }
            if (p.t->right != NULL) {
                q.push(NodeWithHeight(p.t->right, p.h + 1));
            }
            q.pop();
        }
        if (line.size()) {
            res.push_back(line);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    TreeNode *p1 = new TreeNode(3);
    TreeNode *p2 = new TreeNode(9);
    TreeNode *p3 = new TreeNode(20);
    TreeNode *p4 = new TreeNode(15);
    TreeNode *p5 = new TreeNode(7);
    p1->left = p2;
    p1->right = p3;
    p3->left = p4;
    p3->right = p5;
    Solution s;
    vector<vector<int> > res = s.levelOrderBottom(p1);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cin.get();
    return 0;
}
