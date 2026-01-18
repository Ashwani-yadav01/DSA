#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int height(TreeNode* root) {
    if (root == NULL) return 0;
    int leftHt = height(root->left);
    int rightHt = height(root->right);
    return 1 + max(leftHt, rightHt);
}
int countNodes(TreeNode* root) {
   if (root == NULL) return 0;
    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);
    return 1 +leftCount +rightCount;
}
int sumOfNodes(TreeNode* root) {
    if (root == NULL) return 0;
    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);
    return root->val + leftSum + rightSum;
}
int main() {
       TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    // your code here
    cout << "Height of tree: " << height(root) << endl;
    cout << "Count of nodes: " << countNodes(root) << endl;
    cout << "Sum of all nodes: " << sumOfNodes(root) << endl;
    return 0;
}