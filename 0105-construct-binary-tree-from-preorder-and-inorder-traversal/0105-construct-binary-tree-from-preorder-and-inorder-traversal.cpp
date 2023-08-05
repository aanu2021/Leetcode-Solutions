class Solution {
public:
    
    int idx = 0;
    unordered_map<int,int>IndexMap;
    
    TreeNode*BuildBT(vector<int>&preorder,vector<int>&inorder,int low,int high){
        if(low > high) return NULL;
        int value = preorder[idx++];
        TreeNode*root = new TreeNode(value);
        int idx = IndexMap[value];
        root->left = BuildBT(preorder,inorder,low,idx-1);
        root->right = BuildBT(preorder,inorder,idx+1,high);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)     {
        int n = preorder.size();
        for(int i=0;i<n;i++){
            IndexMap[inorder[i]] = i;
        }
        idx = 0;
        TreeNode*root = BuildBT(preorder,inorder,0,n-1);
        return root;
    }
};