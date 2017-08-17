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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeWithBorder(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
    TreeNode* buildTreeWithBorder(vector<int>& inorder, int ii, int ij, vector<int>& postorder, int pi, int pj) {
        if (!postorder.size() || pi == pj) {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[pj - 1]);
        int ipos = -1, ppos = -1;
        for (int i = ii; i < ij; ++i) {
            if (inorder[i] == postorder[pj - 1]) {
                ipos = i;
                break;
            }
        }
        if (ipos > ii) {
            root->left = buildTreeWithBorder(inorder, ii, ipos, postorder, pi, pi + ipos - ii);
        }
        if (ipos < ij - 1) {
            root->right = buildTreeWithBorder(inorder, ipos + 1, ij, postorder, pi + ipos - ii, pj - 1);
        }
        return root;
    }
};

int main() {
    int i[] = { 2, 1, 4, 3, 5 };
    int p[] = { 2, 4, 5, 3, 1 };
    vector<int> inorder(&i[0], &i[5]);
    vector<int> postorder(&p[0], &p[5]);
    Solution s;
    cout << s.buildTree(inorder, postorder)->val << endl;
    cin.get();
    return 0;
}
