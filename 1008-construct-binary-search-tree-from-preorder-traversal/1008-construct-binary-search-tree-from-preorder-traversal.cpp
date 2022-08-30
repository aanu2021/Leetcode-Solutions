class Solution {
public:
    
    /*
    
    Time Complexity  : O(N*logN + N)
    Space Complexity : O(N)
    
    */
    
    int idx=0;
    
    TreeNode*BuildBST(vector<int>&preorder,int left,int right){
        
        if(idx==preorder.size() || preorder[idx]<left || preorder[idx]>right || left>right){
            return NULL;
        }
        
        TreeNode*root=new TreeNode(preorder[idx]);
        
        idx++;
        
        root->left=BuildBST(preorder,left,root->val-1);
        
        root->right=BuildBST(preorder,root->val+1,right);
        
        return root;
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int n=preorder.size();
        
        TreeNode*root=BuildBST(preorder,-1e9,1e9);
        
        return root;
        
    }
};