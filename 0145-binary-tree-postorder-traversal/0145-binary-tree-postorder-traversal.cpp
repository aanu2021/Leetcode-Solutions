class Solution {
public:
    
    vector<int>answer;
    
    void postorder(TreeNode* &root){
        if(!root) return;
        postorder(root->left);
        postorder(root->right);
        answer.push_back(root->val);
    }
    
    void postorder2(TreeNode* &root){
        stack<TreeNode*>S;
        S.push(root);
        while(!S.empty()){
            auto node = S.top(); S.pop();
            answer.push_back(node->val);
            if(node->left){
                S.push(node->left);
            }
            if(node->right){
                S.push(node->right);
            }
        }
        reverse(answer.begin(),answer.end());
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        answer.clear();
        postorder2(root);
        return answer;
    }
};