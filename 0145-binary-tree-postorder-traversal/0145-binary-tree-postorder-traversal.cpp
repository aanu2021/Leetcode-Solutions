class Solution {
public:
    
    vector<int>answer;
    
    void postorder(TreeNode* &root){
        if(!root) return;
        postorder(root->left);
        postorder(root->right);
        answer.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        answer.clear();
        postorder(root);
        return answer;
    }
};