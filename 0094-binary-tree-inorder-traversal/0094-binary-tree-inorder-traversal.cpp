class Solution {
public:
    
    vector<int>answer;
    
    void inorder(TreeNode* &root){
        if(!root) return;
        inorder(root->left);
        answer.push_back(root->val);
        inorder(root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        answer.clear();
        inorder(root);
        return answer;
    }
};