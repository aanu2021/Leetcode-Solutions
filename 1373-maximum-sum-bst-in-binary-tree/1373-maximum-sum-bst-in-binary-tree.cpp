class Solution {
public:
  
    struct Pair{
        int sum;
        int min;
        int max;
        int size;
        bool isBST;
    }; 
    
    Pair func(TreeNode* &root,int &maxSum){
        if(!root) return {0,1000000000,-1000000000,0,true};
        auto left = func(root->left, maxSum);
        auto right = func(root->right, maxSum);
        Pair curr;
        curr.sum = root->val + left.sum + right.sum;
        curr.size = 1 + left.size + right.size;
        curr.min = min({left.min,right.min,root->val});
        curr.max = max({left.max,right.max,root->val});
        curr.isBST = false;
        if(root->val > left.max && root->val < right.min){
            if(left.isBST && right.isBST){
                maxSum = max(maxSum, curr.sum);
                curr.isBST = true;
            }
        }
        return curr;
    }
    
    int maxSumBST(TreeNode* root) {
        if(!root) return 0;
        int maxSum = 0;
        func(root,maxSum);
        return maxSum;
    }
};