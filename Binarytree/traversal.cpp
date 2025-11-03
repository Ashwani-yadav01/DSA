#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Binary Tree Node Structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ----------------------
// 1️⃣  Preorder Traversal (Root, Left, Right)
// ----------------------
void preorder(TreeNode* root, vector<int>& ans) {
    if (root == NULL) return;
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

// ----------------------
// 2️⃣  Inorder Traversal (Left, Root, Right)
// ----------------------
void inorder(TreeNode* root, vector<int>& ans) {
    if (root == NULL) return;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

// ----------------------
// 3️⃣  Postorder Traversal (Left, Right, Root)
// ----------------------
void postorder(TreeNode* root, vector<int>& ans) {
    if (root == NULL) return;
    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->val);
}

// ----------------------
// 4️⃣  Level Order Traversal (BFS)
// ----------------------
  vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL); // Marker for end of level

        vector<int> helper;

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == NULL) {
                ans.push_back(helper);
                helper.clear();

                if (!q.empty()) {
                    q.push(NULL); // Add marker for next level
                }
            } else {
                helper.push_back(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
        }

        return ans;
    }

// ----------------------
// 🧠 Main Function (Example)
// ----------------------
int main() {
    // Create example tree
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> ans;

    // Preorder
    preorder(root, ans);
    cout << "Preorder: ";
    for (int val : ans) cout << val << " ";
    cout << endl;
    ans.clear();

    // Inorder
    inorder(root, ans);
    cout << "Inorder: ";
    for (int val : ans) cout << val << " ";
    cout << endl;
    ans.clear();

    // Postorder
    postorder(root, ans);
    cout << "Postorder: ";
    for (int val : ans) cout << val << " ";
    cout << endl;
    ans.clear();

    // Level Order
    vector<vector<int>> levelAns = levelOrder(root);
    cout << "Level Order: ";
    cout << endl;
    for (auto& level : levelAns) {
        for (int val : level) cout << val << " ";
        cout << endl;
    }
    cout << endl;

    return 0;
}
