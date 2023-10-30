#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> bottomView(Node* root) {
    vector<int> ans;
    if (root == NULL) return ans;
    // Using BFS to create a map
    map<int, int> mp; // {y, nodevalue}
    
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    
    while (!q.empty()) {
        auto frontpair = q.front();
        q.pop();
        
        int y = frontpair.second;
        mp[frontpair.second] = frontpair.first->data;
        
        if (frontpair.first->left) {
            q.push({frontpair.first->left, y - 1});
        }
        
        if (frontpair.first->right) {
            q.push({frontpair.first->right, y + 1});
        }
    }
    
    for (auto pair : mp) {
        ans.push_back(pair.second);
    }
    
    return ans;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    vector<int> bottomViewResult = bottomView(root);

    cout << "Bottom View of the binary tree: ";
    for (int val : bottomViewResult) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}