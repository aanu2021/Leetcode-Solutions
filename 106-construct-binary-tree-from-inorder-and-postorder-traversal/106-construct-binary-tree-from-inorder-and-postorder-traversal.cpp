class Solution {
public:
    
    unordered_map<int,int>mapp;
    
    int idx;
    
    TreeNode*BuildBT(vector<int>&postorder,vector<int>&inorder,int start,int end){
        
        if(start>end){
            return NULL;
        }
        
        TreeNode*root=new TreeNode(postorder[idx--]);
        
        int pivot=mapp[root->val];
        
        root->right=BuildBT(postorder,inorder,pivot+1,end);
        
        root->left=BuildBT(postorder,inorder,start,pivot-1);
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n=inorder.size();
        
        if(n==0){
            return NULL;
        }
        
        idx=n-1;
        
        for(int i=0;i<n;++i){
            mapp[inorder[i]]=i;
        }
        
        TreeNode*root=BuildBT(postorder,inorder,0,n-1);
        
        return root;
        
    }
};