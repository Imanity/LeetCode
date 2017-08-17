#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeWithBorder(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    TreeNode* buildTreeWithBorder(vector<int>& preorder, int pi, int pj, vector<int>& inorder, int ii, int ij) {
        if (!preorder.size() || pi == pj) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[pi]);
        int ipos = -1, ppos = -1;
        for (int i = ii; i < ij; ++i) {
            if (inorder[i] == preorder[pi]) {
                ipos = i;
                break;
            }
        }
        if (ipos > ii) {
            root->left = buildTreeWithBorder(preorder, pi + 1, pi + ipos - ii + 1, inorder, ii, ipos);
        }
        if (ipos < ij - 1) {
            root->right = buildTreeWithBorder(preorder, pj - ij + ipos + 1, pj, inorder, ipos + 1, ij);
        }
        return root;
    }
};

int main() {
    int p[] = { 3, 2, 1, 4, 5 };
    int i[] = { 1, 2, 3, 4, 5 };
    vector<int> preorder(&p[0], &p[5]);
    vector<int> inorder(&i[0], &i[5]);
    Solution s;
    cout << s.buildTree(preorder, inorder)->val << endl;
    cin.get();
    return 0;
}
