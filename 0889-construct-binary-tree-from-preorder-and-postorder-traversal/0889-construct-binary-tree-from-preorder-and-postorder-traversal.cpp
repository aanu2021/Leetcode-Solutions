class Solution {
public:
    
    unordered_map<int,int>index;
    int idx;
    
    TreeNode * BuildBT(vector<int>&preorder,vector<int>&postorder,int low,int high){
        if(low > high || idx < 0) return NULL;
        if(low == high) return new TreeNode(postorder[idx--]);
        
        TreeNode * root = new TreeNode(postorder[idx]);
        int value = postorder[--idx];
        int pre_index = index[value];
        
        
        root->right = BuildBT(preorder,postorder,pre_index,high);
        root->left = BuildBT(preorder,postorder,low+1,pre_index-1);
        return root;
        
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        int n = preorder.size();
        idx = n-1;
        
        for(int i=0;i<n;i++){
            index[preorder[i]] = i;
        }
        
        TreeNode * root = BuildBT(preorder,postorder,0,n-1);
        return root;
        
    }
};