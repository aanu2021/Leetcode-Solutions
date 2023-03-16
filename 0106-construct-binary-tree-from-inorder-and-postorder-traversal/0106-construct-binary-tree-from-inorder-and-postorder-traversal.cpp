class Solution {
public:
    unordered_map<int,int>indexMap;
    int idx;
    
    TreeNode*BuildBT(vector<int>&inorder,vector<int>&postorder,int low,int high){
        if(low > high) return NULL;
        int index = indexMap[postorder[idx]];
        int value = postorder[idx]; idx--;
        TreeNode * root =  new TreeNode(value);
        root->right = BuildBT(inorder,postorder,index + 1 , high); 
        root->left = BuildBT(inorder,postorder,low,index - 1);
        return root;    
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i=0;i<n;i++){
            indexMap[inorder[i]] = i;
        }
        idx = n - 1;
        return BuildBT(inorder,postorder,0,n-1);
    }
};