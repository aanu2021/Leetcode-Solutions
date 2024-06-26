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
    
    void inorderTraversal(TreeNode* &root, vector<int>& nodes){
        if(!root) return;
        inorderTraversal(root->left, nodes);
        nodes.push_back(root->val);
        inorderTraversal(root->right, nodes);
    }
    
    TreeNode * BuildBST(vector<int>&nodes, int low, int high){
        if(low > high) return NULL;
        if(low == high){
            return new TreeNode(nodes[low]);
        }
        int mid = (low + high)/2;
        TreeNode * root = new TreeNode(nodes[mid]);
        root->left = BuildBST(nodes, low, mid-1);
        root->right = BuildBST(nodes, mid+1, high);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return root;
        vector<int>nodes;
        inorderTraversal(root, nodes);
        int n = nodes.size();
        TreeNode * newRoot = BuildBST(nodes, 0, n-1);
        return newRoot;
    }
};