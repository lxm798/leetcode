#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        doInorderTraversal(root, ret);
        return ret;
    }

private:
    void doInorderTraversal(TreeNode* root, vector<int>& ret) {
        if (!root) {
            return;
        }
        if (root->left) {
            doInorderTraversal(root->left, ret);
        }
        ret.push_back(root->val);
        if (root->right) {
            doInorderTraversal(root->right, ret);
        }
    }

    void doInorderTraversalByIteratively(TreeNode* root, vector<int>& ret) {
        stack<TreeNode*> nodeStack;
        TreeNode * cur = root;
        while(cur || !nodeStack.empty()) {
            while(cur) {
                nodeStack.push(cur);
                cur = cur->left;
            }
            if (!nodeStack.empty()) {
                cur = nodeStack.top();
                nodeStack.pop();
                ret.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
};
