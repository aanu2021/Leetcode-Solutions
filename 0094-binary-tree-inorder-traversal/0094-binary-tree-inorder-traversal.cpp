class Solution {
public:
    
    vector<int>answer;
    
    void inorder(TreeNode* &root){
        if(!root) return;
        inorder(root->left);
        answer.push_back(root->val);
        inorder(root->right);
    }
    
    void inorder2(TreeNode* &root){
        stack<TreeNode*>S;
        TreeNode*node = root;
        while(node){
            S.push(node);
            node = node->left;
        }
        while(!S.empty()){
            auto curr = S.top(); S.pop();
            answer.push_back(curr->val);
            if(curr->right){
                curr = curr->right;
                while(curr){
                    S.push(curr);
                    curr = curr->left;
                }
            }
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        answer.clear();
        inorder2(root);
        return answer;
    }
};