class Solution {
public:
    
    int maxval=INT_MIN;
    
    pair<int,int>func(TreeNode*root){
        
        if(root==NULL){
            return {-1e9,-1e9};
        }
        
        if(root!=NULL && root->left==NULL && root->right==NULL){
            maxval=max(maxval,root->val);
            return {root->val,root->val};
        }
        
        pair<int,int>left=func(root->left);
        pair<int,int>right=func(root->right);
        
        pair<int,int>curr={root->val,root->val};
        
        curr.first=max(curr.first,root->val+max(left.first,right.first));
        
        curr.second=max(curr.second,root->val+left.first+right.first);
        curr.second=max(curr.second,max(left.second,right.second));
        
        maxval=max(maxval,max(curr.first,curr.second));
        
        return curr;
        
    }
    
    int maxPathSum(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        
        func(root);
        
        return maxval;
        
    }
};