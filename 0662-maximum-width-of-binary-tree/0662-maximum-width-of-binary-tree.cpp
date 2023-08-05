class Solution {
public:
    
    typedef long long ll;
    
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        ll maxLevel = 0LL;
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0LL});
        while(!q.empty()){
            int sz = q.size();
            ll left = -1LL, right = -1LL;
            while(sz--){
                auto curr = q.front(); q.pop();
                auto node = curr.first;
                ll lvl = curr.second;
                if(left == -1){
                    left = lvl;
                }
                right = lvl;
                ll currLevel = (right-left+1LL);
                maxLevel = max(maxLevel, currLevel);
                if(node->left){
                    q.push({node->left,2*currLevel});
                }
                if(node->right){
                    q.push({node->right,2*currLevel + 1});
                }
            }
        }
        return maxLevel;
    }
};