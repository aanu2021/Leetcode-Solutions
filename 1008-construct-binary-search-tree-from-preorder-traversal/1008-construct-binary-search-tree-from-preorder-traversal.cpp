class Solution {
public:
    
    /*
    
    Time Complexity  : O(N*H)
    Space Complexity : O(1)
    
    */
    
    int idx=0;
    
    unordered_map<int,int>index;
    
    TreeNode*BuildBST(vector<int>&preorder,vector<int>&inorder,int low,int high){
        
        if(low>high){
            return NULL;
        }
        
        TreeNode*root=new TreeNode(preorder[idx]);
        
        int mid=index[preorder[idx]];
        
        idx++;
        
        root->left=BuildBST(preorder,inorder,low,mid-1);
        
        root->right=BuildBST(preorder,inorder,mid+1,high);
        
        return root;
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int n=preorder.size();
        
        vector<int>inorder=preorder;
        
        sort(inorder.begin(),inorder.end());
        
        for(int i=0;i<n;++i){
            index[inorder[i]]=i;
        }
        
        TreeNode*root=BuildBST(preorder,inorder,0,n-1);
        
        return root;
        
    }
};