/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode*node=NULL;
    
    void dfs(TreeNode*original,TreeNode*cloned,TreeNode*target){
        
        if(original==NULL){
            return;
        }
        
        if(original==target){
            node=cloned;
            return;
        }
        
        dfs(original->left,cloned->left,target);
        dfs(original->right,cloned->right,target);
        
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        dfs(original,cloned,target);
        return node;
    }
};