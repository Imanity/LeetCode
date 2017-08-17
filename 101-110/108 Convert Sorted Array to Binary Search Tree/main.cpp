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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (!nums.size()) {
            return NULL;
        }
        int pos = nums.size() / 2;
        TreeNode *root = new TreeNode(nums[pos]);
        vector<int> leftTree(&nums[0], &nums[pos]);
        vector<int> rightTree(&nums[pos + 1], &nums[nums.size()]);
        root->left = sortedArrayToBST(leftTree);
        root->right = sortedArrayToBST(rightTree);
        return root;

    }
};

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    vector<int> vec(&arr[0], &arr[5]);
    Solution s;
    TreeNode *t = s.sortedArrayToBST(vec);
    cout << t->val << endl;
    cin.get();
    return 0;
}
