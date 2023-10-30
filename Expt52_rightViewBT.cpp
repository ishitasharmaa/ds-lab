#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void f(Node* root, int level, vector<int>& ans) {
    if (root == NULL) return;
    if (ans.size() == level) ans.push_back(root->data);

    f(root->right, level + 1, ans);
    f(root->left, level + 1, ans);
}

vector<int> rightView(Node* root) {
    vector<int> ans;
    if (root == NULL) return ans;
    f(root, 0, ans);
    return ans;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> rightViewResult = rightView(root);

    cout << "Right View of the binary tree: ";
    for (int val : rightViewResult) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
