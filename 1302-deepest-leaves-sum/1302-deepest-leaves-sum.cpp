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
   
    int func(TreeNode*root){
        
       if(root==NULL){
           return 0;
       }
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        int level=0;
        
        map<int,int>mp;
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                 auto node=q.front();
                 q.pop();
            
                 mp[level]+=node->val;
                
                if(node->left!=NULL){
                    q.push(node->left);
                }
                
                if(node->right!=NULL){
                    q.push(node->right);
                }
                
            }
            
            level++;
            
        }
        
        return mp[level-1];
        
    }
    
    int deepestLeavesSum(TreeNode* root) {
        
        int ans=func(root);
        
        return ans;
        
    }
};