class Solution {
public:
    
    int ans=0;
    
    pair<int,int>func(TreeNode*root){
        
        if(root==NULL){
            return {0,0};
        }
        
        pair<int,int>left=func(root->left);
        pair<int,int>right=func(root->right);
        
        int longest_path=1+max(left.first,right.first);
        
        int internal_path=1+left.first+right.first;
        
        ans=max(ans,max(longest_path,internal_path));
        
        return {longest_path,internal_path};
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        
        func(root);
        
        return ans-1;
        
    }
};