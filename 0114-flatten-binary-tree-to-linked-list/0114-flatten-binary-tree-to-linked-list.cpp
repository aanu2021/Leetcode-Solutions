/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        if(!root->left && !root->right) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode*leftChild = root->left;
        TreeNode*rightChild = root->right;
        root->left = NULL;
        root->right = leftChild;
        TreeNode*tmp = root;
        while(tmp && tmp->right){
            tmp = tmp->right;
        }
        tmp->right = rightChild;
    }
};