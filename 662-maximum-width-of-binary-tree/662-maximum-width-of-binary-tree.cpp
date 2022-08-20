class Solution {
public:
    
    typedef long long ll;
    
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root){
            return 0;
        }
        
        queue<pair<TreeNode*,ll>>q;
        
        q.push({root,0LL});
        
        
        ll ans=0LL;
        
        
        while(!q.empty()){
            
            int sz=q.size();
            
            ll left=-1,right=-1;
            
            while(sz--){
                
                auto curr=q.front();
                q.pop();
                
                auto node=curr.first;
                
                ll lvl=curr.second;
                
                if(left==-1){
                    left=lvl;
                }
                
                right=lvl;
                
                ll current=(right-left);
                
                ans=max(ans,current+1LL);
                
                
                if(node->left){
                    q.push({node->left,2*current});
                }
                
                if(node->right){
                    q.push({node->right,2*current+1});
                }
                
            }
            
        }
        
        return ans;
        
    }
};