class Solution {
public:
    
    void inorder(TreeNode* root,vector<int>& answer){
        if(!root) return;
        inorder(root->left, answer);
        answer.push_back(root->val);
        inorder(root->right, answer);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>answer;
        inorder(root,answer);
        return answer;
    }
};