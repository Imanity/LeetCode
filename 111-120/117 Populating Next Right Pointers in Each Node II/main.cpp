#include <iostream>
#include <queue>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) {
            return;
        }
        queue<TreeLinkNode *> q;
        q.push(root);
        int num = 1;
        TreeLinkNode *last = NULL;
        while (true) {
            bool isEnd = true;
            TreeLinkNode *p = NULL;
            int qNum = q.size();
            for (int i = 0; i < qNum; ++i) {
                p = q.front();
                q.pop();
                if (p == NULL) {
                    continue;
                }
                if (p->left != NULL || p->right != NULL) {
                    isEnd = false;
                }
                q.push(p->left);
                q.push(p->right);
                if (last != NULL) {
                    last->next = p;
                }
                last = p;
            }
            last = NULL;
            num *= 2;
            if (isEnd) {
                break;
            }
        }
    }
};

int main() {
    TreeLinkNode *p[5];
    for (int i = 0; i < 5; ++i) {
        p[i] = new TreeLinkNode(i + 1);
    }
    p[0]->left = p[1];
    p[0]->right = p[2];
    p[1]->right = p[3];
    p[2]->left = p[4];
    Solution s;
    s.connect(p[0]);
    cout << p[3]->next->val << endl;
    cin.get();
    return 0;
}
