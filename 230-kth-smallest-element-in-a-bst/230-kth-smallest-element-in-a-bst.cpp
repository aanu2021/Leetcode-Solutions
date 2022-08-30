
class Solution {
public:
    
    int cnt=0;
    
    int ans=-1;
    
    void inorder(TreeNode*&root,int k){
        
        if(!root || cnt==k){
            return;
        }
        
        inorder(root->left,k);
        
        cnt++;
        
        if(cnt==k){
            ans=root->val;
            return;
        }
        
        inorder(root->right,k);
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        if(!root){
            return -1;
        }
        
        inorder(root,k);
        
        return ans;
        
    }
};