class Solution {
public:
    
    void inorderRecursive(TreeNode* root,vector<int>& answer){
        if(!root) return;
        inorderRecursive(root->left, answer);
        answer.push_back(root->val);
        inorderRecursive(root->right, answer);
    }
    
    void inorderIterative(TreeNode* root,vector<int>& answer){
        if(!root) return;
        stack<TreeNode*>S;
        TreeNode*curr = root;
        while(!S.empty() || curr){
            while(curr){
                S.push(curr);
                curr = curr->left;
            }
            TreeNode*current = S.top(); S.pop();
            answer.push_back(current->val);
            if(current->right) curr = current->right;
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>answer;
        inorderIterative(root,answer);
        // inorderRecursive(root,answer);
        return answer;
    }
};