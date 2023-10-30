#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

TreeNode* createTreeFromLevelOrder(vector<int>& levelOrder) {
    if (levelOrder.empty()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(levelOrder[0]);
    queue<TreeNode*> q;
    q.push(root);

    int index = 1;
    while (index < levelOrder.size()) {
        TreeNode* currentNode = q.front();
        q.pop();

        if (index < levelOrder.size() && levelOrder[index] != -1) {
            currentNode->left = new TreeNode(levelOrder[index]);
            q.push(currentNode->left);
        }
        index++;

        if (index < levelOrder.size() && levelOrder[index] != -1) {
            currentNode->right = new TreeNode(levelOrder[index]);
            q.push(currentNode->right);
        }
        index++;
    }

    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {

    vector<int> levelOrder;
    levelOrder.push_back(3);
    levelOrder.push_back(9);
    levelOrder.push_back(20);
    levelOrder.push_back(-1);
    levelOrder.push_back(-1);
    levelOrder.push_back(15);
    levelOrder.push_back(7);

    TreeNode* root = createTreeFromLevelOrder(levelOrder);

    cout << "Inorder traversal of the constructed tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
