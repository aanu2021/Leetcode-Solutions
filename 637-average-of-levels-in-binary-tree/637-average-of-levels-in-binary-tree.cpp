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
    
    typedef long long ll;
    
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double>ans;
        
        if(!root){
            return {};
        }
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty()){
            
            int sz=q.size();
            
            ll sum=0LL;
            
            for(int i=0;i<sz;++i){
                
                auto node=q.front();
                q.pop();
                
                sum+=(ll)node->val;
                
                if(node->left){
                    q.push(node->left);
                }
                
                if(node->right){
                    q.push(node->right);
                }
                
            }
            
            double curr=(double)sum/(double)sz;
            
            ans.push_back(curr);
            
        }
        
        return ans;
        
    }
};