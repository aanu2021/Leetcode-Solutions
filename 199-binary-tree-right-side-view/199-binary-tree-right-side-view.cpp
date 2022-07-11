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
    
    vector<int>ans;
    
    void func(TreeNode*root,int lvl){
        
        if(root==NULL){
            return;
        }
        
        int sz=ans.size();
        
        if(sz>lvl){
            
            ans[lvl]=root->val;
            
        }
        
        else{
            
            ans.push_back(root->val);
            
        }
       
        func(root->left,lvl+1);
        
        func(root->right,lvl+1);
        
    }
    
    vector<int> rightSideView(TreeNode* root) {
        
        if(root==NULL){
            return {};
        }
     
        ans.push_back(-1);
        
        func(root,1);
        
        reverse(ans.begin(),ans.end());
        
        ans.pop_back();
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};