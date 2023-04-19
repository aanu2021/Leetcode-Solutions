class Solution {
public:
    
    pair<int,int> dfs(TreeNode*& root,int& maxLen){
        if(!root) return {0,0};
        auto left = dfs(root->left,maxLen);
        auto right = dfs(root->right,maxLen);
        pair<int,int>current;
        current.first = 1 + left.second;
        current.second = 1 + right.first;
        maxLen = max({maxLen,current.first,current.second});
        return current;
    } 
    
    int longestZigZag(TreeNode* root) {
        if(!root) return 0;
        int maxLen = 0;
        dfs(root,maxLen);
        return maxLen - 1;
    }
};