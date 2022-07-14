class Solution {
public:
    
    map<int,int>mp;
    
    int pos=0;
    
    TreeNode*BuildTree(vector<int>&preorder,vector<int>&inorder, int low,int high){
        
        if(low>high){
            
            return NULL;
            
        }
        
        TreeNode*root=new TreeNode(preorder[pos]);
        
        int temp=preorder[pos];
        
        pos++;
        
        int index=mp[temp];
        
        root->left=BuildTree(preorder,inorder,low,index-1);
        
        root->right=BuildTree(preorder,inorder,index+1,high);
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n=preorder.size();
        
        for(int i=0;i<n;++i){
            
            mp[inorder[i]]=i;
            
        }
        
        TreeNode*root=BuildTree(preorder,inorder,0,n-1);
        
        return root;
        
    }
};