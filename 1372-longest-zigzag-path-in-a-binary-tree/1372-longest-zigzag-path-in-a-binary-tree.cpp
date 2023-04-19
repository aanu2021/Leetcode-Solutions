class Solution {
public:
    
    int maxLen;
    
    pair<int,int>dfs(TreeNode* &root){
        
        if(!root) return {0,0};
        if(!root->left && !root->right) return {1,1};
        
        auto left  = dfs(root->left);
        auto right = dfs(root->right);
        
        pair<int,int>curr;
        curr.first = 1 + right.second;
        curr.second = 1 + left.first;
        maxLen = max({maxLen,curr.first,curr.second});
        return curr;
        
    }
    
    int longestZigZag(TreeNode* root) {
        if(!root) return 0;
        maxLen = 1;
        pair<int,int>answer = dfs(root);
        return maxLen - 1;
    }
};