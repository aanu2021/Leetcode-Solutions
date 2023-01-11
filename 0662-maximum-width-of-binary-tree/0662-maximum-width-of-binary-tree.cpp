class Solution {
public:
    
    typedef long long ll;
    
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root) return 0;
        
        ll ans = 0LL;
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0LL});
        
        while(!q.empty()){
            int sz = q.size();
            ll left = -1LL,right = -1LL;
            while(sz--){
                auto curr = q.front();
                q.pop();
                auto node = curr.first;
                ll lvl = curr.second;
                if(left == -1) left = lvl;
                right = lvl;
                ll currlvl = (right-left+1);
                ans = max(ans,currlvl);
                if(node->left){
                    q.push({node->left,2*currlvl+1});
                }
                if(node->right){
                    q.push({node->right,2*currlvl+2});
                }
            }
        }
        
        return ans;
        
    }
};