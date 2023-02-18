
class Solution {
public:
    
    void DFS(TreeNode*&root){
        if(!root) return;
        TreeNode * tempLeft = root->left;
        TreeNode * tempRight = root->right;
        root->left = tempRight;
        root->right = tempLeft;
        DFS(root->left);
        DFS(root->right);
    }
    
    TreeNode * BFS(TreeNode *& root){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            TreeNode * tempLeft = node->left;
            TreeNode * tempRight = node->right;
            node->left = tempRight;
            node->right = tempLeft;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return root;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        // DFS(root);
        return BFS(root);
    }
};