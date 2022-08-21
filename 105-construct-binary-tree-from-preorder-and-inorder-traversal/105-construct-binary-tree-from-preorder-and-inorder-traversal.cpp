class Solution {
public:
    
    unordered_map<int,int>mapp;
    
    int idx=0;
    TreeNode*BuildBT(vector<int>&preorder,vector<int>&inorder,int start,int end){
        
        if(start>end){
            return NULL;
        }
        
        TreeNode*root=new TreeNode(preorder[idx++]);
        
        int pivot=mapp[root->val];
        
        root->left=BuildBT(preorder,inorder,start,pivot-1);
        root->right=BuildBT(preorder,inorder,pivot+1,end);
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n=preorder.size();
        
        for(int i=0;i<n;++i){
            mapp[inorder[i]]=i;
        }
        
        TreeNode*root=BuildBT(preorder,inorder,0,n-1);
        
        return root;
        
    }
};