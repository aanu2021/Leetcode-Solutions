class Solution {
public:
    
    void dfs(TreeNode* &root,int lvl,int &minimumDepth){
        if(!root) return ;
        if(!root->left && !root->right) minimumDepth = min(minimumDepth,lvl);
        dfs(root->left,lvl+1,minimumDepth);
        dfs(root->right,lvl+1,minimumDepth);
    }
    
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int minimumDepth = INT_MAX;
        dfs(root,1,minimumDepth);
        return minimumDepth;
    }
};