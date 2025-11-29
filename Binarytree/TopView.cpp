#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to print Top View
vector<int> topView(Node* root) {
    vector<int> ans;
    if (!root) return ans;

    // Map to store first node at every horizontal distance
    map<int, int> mp;

    // Queue for BFS → contains node + horizontal distance
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        Node* node = p.first;
        int hd = p.second;

        // Store first node of every horizontal distance
        if (mp.find(hd) == mp.end()) {
            mp[hd] = node->data;
        }

        if (node->left)
            q.push({node->left, hd - 1});
        if (node->right)
            q.push({node->right, hd + 1});
    }

    // Traverse horizontal distances in sorted order
    for (auto it : mp)
        ans.push_back(it.second);

    return ans;
}

int main() {
    /*
           1
         /   \
        2     3
       / \   / \
      4   5 6   7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = topView(root);

    for (int x : result) cout << x << " ";
}
