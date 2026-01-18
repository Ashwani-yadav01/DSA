#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* buildTree(const vector<int>& preorder, int& index) {
    if (index >= preorder.size() || preorder[index] == -1) {
        index++;
        return NULL;
    }

    TreeNode* root = new TreeNode(preorder[index++]);
    root->left = buildTree(preorder, index);
    root->right = buildTree(preorder, index);
    return root;
}
int main() {
    vector<int> preorder={3,2,-1,-1,4,-1,-1,5,-1,-1};
    int index = 0;
    TreeNode* root = buildTree(preorder, index);
    
    // your code here
    
    return 0;
}