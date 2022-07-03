
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        
        vector<int>ans(10005,INT_MIN);
        
        if(root==NULL){
            return {};
        }
        
        int level=0;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                auto node=q.front();
                q.pop();
                
                ans[level]=max(ans[level],node->val);
                
                if(node->left!=NULL){
                    q.push(node->left);
                }  
                
                if(node->right!=NULL){
                    q.push(node->right);
                }
                
            }
            
            level++;
            
        }
        
        ans.resize(level);
        
        return ans;
        
    }
};