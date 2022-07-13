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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root==NULL){
            return {};
        }
        
        vector<vector<int>>level(2002);
        
        int lvl=0;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                auto node=q.front();
                q.pop();
                
                level[lvl].push_back(node->val);
                
                if(node->left!=NULL){
                    q.push(node->left);
                }
                
                if(node->right!=NULL){
                    q.push(node->right);
                }
                
            }
            
            lvl++;
            
        }
        
        level.resize(lvl);
        
        return level;
        
    }
};