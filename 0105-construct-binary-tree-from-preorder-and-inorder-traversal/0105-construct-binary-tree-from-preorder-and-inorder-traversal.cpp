class Solution {
public:
    
    unordered_map<int,int>index;
    int idx = 0;
    
    TreeNode * BuildBT(vector<int>&preorder,vector<int>&inorder,int low,int high){
        
        if(low > high) return NULL;
        if(low == high) return new TreeNode(preorder[idx++]);
        
        TreeNode * root = new TreeNode(preorder[idx]);
        int value = preorder[idx++];
        int inorder_pos = index[value];
        
        root->left = BuildBT(preorder,inorder,low,inorder_pos-1);
        root->right = BuildBT(preorder,inorder,inorder_pos+1,high);
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = preorder.size();
        
        for(int i=0;i<n;i++){
            index[inorder[i]] = i;
        }
        
        TreeNode * root = BuildBT(preorder,inorder,0,n-1);
        return root;
        
    }
};