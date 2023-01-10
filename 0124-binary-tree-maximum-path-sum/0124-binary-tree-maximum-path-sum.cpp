class Solution {
public:
    
    int findPathSum(TreeNode*&root,int &maxSum){
        if(!root) return 0;
        int left_path_sum = findPathSum(root->left,maxSum);
        int right_path_sum = findPathSum(root->right,maxSum);
        int internal_path = root->val + max(left_path_sum,0) + max(right_path_sum,0);
        int longest_path = root->val + max({left_path_sum,right_path_sum,0});
        maxSum = max(maxSum,internal_path);
        return longest_path;
    }
    
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int maxSum = INT_MIN;
        findPathSum(root,maxSum);
        return maxSum;
    }
};