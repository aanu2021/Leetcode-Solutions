class Solution {
public:
    
    vector<int>answer;
    
    void preorder(TreeNode* &root){
        if(!root) return;
        answer.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    
    void preorder2(TreeNode* &root){
        stack<TreeNode*>S;
        S.push(root);
        while(!S.empty()){
            auto node = S.top();
            S.pop();
            answer.push_back(node->val);
            if(node->right){
                S.push(node->right);
            }
            if(node->left){
                S.push(node->left);
            }
        }
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        answer.clear();
        preorder2(root);
        return answer;
    }
};