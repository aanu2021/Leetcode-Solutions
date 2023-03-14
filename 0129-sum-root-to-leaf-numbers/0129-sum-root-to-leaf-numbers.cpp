class Solution {
public:
    
    void dfs(TreeNode*& root,int currSum,int &totalSum){
        if(!root) return;
        currSum = (currSum*10) + (root->val);
        if(!root->left && !root->right) totalSum += currSum;
        dfs(root->left,currSum,totalSum);
        dfs(root->right,currSum,totalSum);
    }
    
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int totalSum = 0;
        dfs(root,0,totalSum);
        return totalSum;
    }
};