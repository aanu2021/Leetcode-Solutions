class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root==NULL){
            
            return {};
            
        }
        
        vector<vector<int>>ans(2002);
        
        int level=0;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                auto curr=q.front();
                q.pop();
                
                ans[level].push_back(curr->val);
                
                if(curr->left){
                    q.push(curr->left);
                }
                
                if(curr->right){
                    q.push(curr->right);
                }
                
            }
            
            if(level%2){
                
                reverse(ans[level].begin(),ans[level].end());
                
                
            }
            
            level++;
            
        }
        
        ans.resize(level);
        
        return ans;
        
    }
};