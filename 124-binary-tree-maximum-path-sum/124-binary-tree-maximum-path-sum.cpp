/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
        
        maxval=max(maxval,max(left.first,left.second));
        maxval=max(maxval,max(right.first,right.second));
        
        pair<int,int>curr={root->val,root->val};
        
        curr.first=root->val+max(left.first,right.first);
        curr.second=root->val+left.first+right.first;
        
        curr.first=max(curr.first,root->val);
        curr.second=max(curr.second,root->val);
        
        curr.second=max(curr.second,max(left.second,right.second));
        
        maxval=max(maxval,max(curr.first,curr.second));
        
        return curr;
        
    }
    
    int maxPathSum(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        
        pair<int,int>ans=func(root);
        
        return maxval;
        
    }
};