#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the BST
TreeNode *insert(TreeNode *root, int value)
{
    if (root == nullptr)
    {
        return new TreeNode(value);
    }

    if (value < root->val)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->val)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to search for a value in the BST
bool search(TreeNode *root, int value)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->val == value)
    {
        return true;
    }
    else if (value < root->val)
    {
        return search(root->left, value);
    }
    else
    {
        return search(root->right, value);
    }
}
void inorderTraversal(TreeNode* root){
    if(root==NULL)
        return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}
int main()
{
    TreeNode *root = nullptr;

    // Insert nodes into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    int valueToSearch = 40;

    cout << "Inorder traversal of the BST: ";
    inorderTraversal(root);
    cout << endl;

    if (search(root, valueToSearch))
    {
        cout << valueToSearch << " found in the BST." << endl;
    }
    else
    {
        cout << valueToSearch << " not found in the BST." << endl;
    }

    return 0;
}
