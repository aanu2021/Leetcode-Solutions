class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        if(!root){
            return {};
        }
        
        queue<TreeNode*>q;
        
        vector<int>ans;
        
        q.push(root);
        
        int maxlevel=-1;
        
        int lvl=0;
        
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                auto curr=q.front();
                q.pop();
                
                if(lvl>maxlevel){
                    
                    maxlevel=lvl;
                    
                    ans.push_back(curr->val);
                    
                }
                
                if(curr->right){
                    
                    q.push(curr->right);
                    
                }
                
                if(curr->left){
                    
                    q.push(curr->left);
                    
                }
                
            }
            
            lvl++;
            
        }
        
        return ans;
        
    }
};