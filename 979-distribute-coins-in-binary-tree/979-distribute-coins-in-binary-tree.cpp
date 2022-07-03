class Solution {
public:
    
    int ans=0;
    
    int func(TreeNode*root){
        
        if(root==NULL){
            return 0;
        }
        
        int L=func(root->left);
        int R=func(root->right);
        
        ans+=abs(L)+abs(R);
        
        return L+R+root->val-1;
        
    }
    
    int distributeCoins(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        
        func(root);
        
        return ans;
        
    }
};