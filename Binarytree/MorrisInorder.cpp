#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> morrisInorder(TreeNode* root) {
    vector<int> ans;
    TreeNode* cur = root;

    while (cur != nullptr) {

        // Case 1: no left child → visit and move right
        if (cur->left == nullptr) {
            ans.push_back(cur->val);
            cur = cur->right;
        }

        // Case 2: left child exists → find predecessor
        else {
            TreeNode* pred = cur->left;

            // Move to rightmost node of left subtree
            while (pred->right != nullptr && pred->right != cur) {
                pred = pred->right;
            }

            // Case 2a: thread not created → create thread & go left
            if (pred->right == nullptr) {
                pred->right = cur;       // create thread
                cur = cur->left;
            }
            // Case 2b: thread exists → remove it & visit node
            else {
                pred->right = nullptr;   // remove thread
                ans.push_back(cur->val); // visit current
                cur = cur->right;
            }
        }
    }
    return ans;
}

int main() {
    // Example:
    //        4
    //       / \
    //      2   5
    //     / \
    //    1   3
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    vector<int> inorder = morrisInorder(root);

    for (int x : inorder) cout << x << " ";
    return 0;
}
