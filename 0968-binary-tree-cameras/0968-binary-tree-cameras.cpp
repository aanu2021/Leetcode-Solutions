
class Solution {
public:
    
    // dp[u][0] -> down subtrees are covered excluding current node
    // dp[u][1] -> down subtrees are covered along with current node, without placing a camera on the current node.
    
    vector<int>dfs(TreeNode* &root){
        
        if(!root){
            return {0,0,1000000};
        }
        
        vector<int>L = dfs(root->left);
        vector<int>R = dfs(root->right);
        
        int mL12 = min(L[1],L[2]);
        int mR12 = min(R[1],R[2]);
        
        int d0 = L[1] + R[1];
        int d1 = min(L[2] + mR12, R[2] + mL12);
        int d2 = 1 + min(L[0],mL12) + min(R[0],mR12);
        
        return {d0,d1,d2};
        
    }
    
    int minCameraCover(TreeNode* root) {
        
        if(!root) return 0;
        
        vector<int>ans = dfs(root);
        
        return min(ans[1],ans[2]);
        
    }
};