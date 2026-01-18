#include <bits/stdc++.h>
using namespace std;

// Node structure for the binary tree
struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to compute the top view of a binary tree
vector<int> topView(Node* root) {
    if (!root)
        return {};

    queue<pair<Node*, int>> q;       // Node pointer + horizontal distance
    map<int, int> topNodes;          // HD -> first node value
    q.push({root, 0});

    while (!q.empty()) {
        pair<Node*, int> frontPair = q.front();
        q.pop();

        Node* node = frontPair.first;
        int hd = frontPair.second;

        // Store the first node encountered at each horizontal distance
        if (topNodes.find(hd) == topNodes.end())
            topNodes[hd] = node->val;

        // Add children with updated HDs
        if (node->left)
            q.push({node->left, hd - 1});
        if (node->right)
            q.push({node->right, hd + 1});
    }

    // Collect result in order of HD
    vector<int> result;
    for (auto it = topNodes.begin(); it != topNodes.end(); ++it)
        result.push_back(it->second);

    return result;
}

// Example usage
int main() {
    /*
            1
           / \
          2   3
           \   \
            4   5
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);

    vector<int> view = topView(root);

    cout << "Top View: ";
    for (int val : view)
        cout << val << " ";
    cout << endl;

    return 0;
}
