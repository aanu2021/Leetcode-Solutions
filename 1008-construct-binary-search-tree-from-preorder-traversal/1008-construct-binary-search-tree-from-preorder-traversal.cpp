class Solution {
public:
    
    int idx=0;
    
    TreeNode*BuildBST(vector<int>&preorder,int low,int high){
        
        if(idx==preorder.size() || preorder[idx]<low || preorder[idx]>high || low>high){
            
            return NULL;
            
        }
        
        TreeNode*root=new TreeNode(preorder[idx++]);
        
        root->left=BuildBST(preorder,low,root->val-1);
        
        root->right=BuildBST(preorder,root->val+1,high);
        
        return root;
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int n=preorder.size();
        
        TreeNode*root=BuildBST(preorder,-1e9,1e9);
        
        return root;
        
    }
};