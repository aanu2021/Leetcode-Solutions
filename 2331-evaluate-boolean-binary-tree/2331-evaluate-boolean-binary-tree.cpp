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
    bool evaluateTree(TreeNode* root) {
        
        if(!root) return true;
        if(!root->left && !root->right) return root->val > 0 ? true : false;
        bool leftValue = evaluateTree(root->left);
        bool rightValue = evaluateTree(root->right);
        
        return root->val == 2 ? (leftValue | rightValue) : (leftValue & rightValue);
    }
};