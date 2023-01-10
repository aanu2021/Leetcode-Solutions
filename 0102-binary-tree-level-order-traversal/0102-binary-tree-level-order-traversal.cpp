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
    
    vector<vector<int>>levels;
    
    void dfs(TreeNode*&root,int lvl){
        if(!root) return;
        if(levels.size() == lvl){
            levels.push_back({root->val});
        }
        else{
            levels[lvl].push_back({root->val});
        }
        dfs(root->left,lvl+1);
        dfs(root->right,lvl+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        dfs(root,0);
        return levels;
    }
};