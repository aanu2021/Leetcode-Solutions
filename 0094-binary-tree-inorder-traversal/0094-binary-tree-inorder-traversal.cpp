class Solution {
public:
    
    void inorder_recursive(TreeNode*&root,vector<int>&inorder_arr)
    {
        
        if(!root) return;
        inorder_recursive(root->left,inorder_arr);
        inorder_arr.push_back(root->val);
        inorder_recursive(root->right,inorder_arr);
        
    }
    
    void inorder_iterative(TreeNode*&root,vector<int>&inorder_arr)
    {
        
        if(!root) return;
        stack<TreeNode*>S;
        TreeNode*curr = root;
        
        while(curr || !S.empty()){
            
            while(curr){
                S.push(curr);
                curr = curr->left;
            }
            
            curr = S.top();
            S.pop();
            inorder_arr.push_back(curr->val);
            curr = curr->right;
            
        }
        
    }    
    
    void inorder_Morris_Traversal(TreeNode*&root,vector<int>&inorder_arr)
    {
        
        TreeNode*curr = root;
        
        while(curr){
            
            if(curr->left == NULL){
                inorder_arr.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode*prev = curr->left;
                while(prev && prev->right && prev->right!=curr){
                    prev = prev->right;
                }
                if(prev->right == curr){
                    inorder_arr.push_back(curr->val);
                    prev->right = NULL;
                    curr = curr->right;
                }
                else{
                    prev->right = curr;
                    curr = curr->left;
                }
            }
            
        }
        
    }    
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        if(!root) return {};
        vector<int>inorder_arr;
        // inorder_recursive(root,inorder_arr);
        // inorder_iterative(root,inorder_arr);
        inorder_Morris_Traversal(root,inorder_arr);
        return inorder_arr;
        
    }
};