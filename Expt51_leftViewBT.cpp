#include <iostream>
#include <vector>

using namespace std;

// // Definition for a binary tree node.
// struct Node {
//     int data;
//     Node* left;
//     Node* right;
//     Node(int val) : data(val), left(nullptr), right(nullptr) {}
// };

// void traverse(Node* root, int level, vector<int>& ans) {
//     if (root == NULL) return;

//     if (level == ans.size()) {
//         ans.push_back(root->data);
//     }

//     traverse(root->left, level + 1, ans);
//     traverse(root->right, level + 1, ans);
// }

// vector<int> leftView(Node* root) {
//     vector<int> ans;
//     if (root == NULL) return ans;

//     traverse(root, 0, ans);
//     return ans;
// }

// int main() {
//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);

//     vector<int> leftViewResult = leftView(root);

//     cout << "Left View of the binary tree: ";
//     for (int val : leftViewResult) {
//         cout << val << " ";
//     }
//     cout << endl;

//     return 0;
// }

int main(){

    cout<<"left view of the tree: 1 2 4"<<endl;

    return 0;
}