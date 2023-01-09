class Solution {
public:
    
    void preorder_recursive(TreeNode*&root,vector<int>&preorder_arr)
    {
        
        if(!root) return;
        preorder_arr.push_back(root->val);
        preorder_recursive(root->left,preorder_arr);
        preorder_recursive(root->right,preorder_arr);
        
    }  
    
    void preorder_iterative(TreeNode*&root,vector<int>&preorder_arr)
    {
        
        if(!root) return ;
        
        stack<TreeNode*>S;
        S.push(root);
        
        while(!S.empty()){
            
            auto node = S.top();
            S.pop();
            
            preorder_arr.push_back(node->val);
            
            if(node->right){
                S.push(node->right);
            }
            if(node->left){
                S.push(node->left);
            }
            
        }
        
    }    
    
    void preorder_Morris_Traversal(TreeNode*&root,vector<int>&preorder_arr)
    {
        
        TreeNode*curr = root;
        
        while(curr){
            
            if(curr->left == NULL){
                preorder_arr.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode * prev = curr->left;
                while(prev && prev->right!=NULL && prev->right!=curr)
                {
                    prev = prev->right;
                }    
                if(prev->right == NULL){
                    preorder_arr.push_back(curr->val);
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
            
        }
        
    }    
    
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int>preorder_arr;
        // preorder_recursive(root,preorder_arr);
        // preorder_iterative(root,preorder_arr);
        preorder_Morris_Traversal(root,preorder_arr);
        return preorder_arr;
    }
};