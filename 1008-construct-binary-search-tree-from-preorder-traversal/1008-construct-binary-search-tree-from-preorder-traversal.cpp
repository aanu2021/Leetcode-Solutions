class Solution {
public:
    
    TreeNode*insert(TreeNode*&root,int target){
        
        if(root==NULL){
            return new TreeNode(target);
        }
        
        if(root->val>target){
            root->left=insert(root->left,target);
        }
        
        else{
            root->right=insert(root->right,target);
        }
        
        return root;
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int n=preorder.size();
        
        TreeNode*root=new TreeNode(preorder[0]);
        
        for(int i=1;i<n;++i){
            
            root=insert(root,preorder[i]);
            
        }
        
        return root;
        
    }
};