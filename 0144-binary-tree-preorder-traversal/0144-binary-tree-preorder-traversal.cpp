class Solution {
public:
    
    vector<int>answer;
    
    void preorder(TreeNode* &root){
        if(!root) return;
        answer.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        preorder(root);
        return answer;
    }
};