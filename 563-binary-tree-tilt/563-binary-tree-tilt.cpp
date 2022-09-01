/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int func(TreeNode*&root,int &sum){
        
        if(!root){
            return 0;
        }
        
        int left_sum=func(root->left,sum);
        
        int right_sum=func(root->right,sum);
        
        sum+=abs(left_sum-right_sum);
        
        return root->val + left_sum + right_sum;
        
    }
    
    int findTilt(TreeNode* root) {
        
        if(!root){
            return 0;
        }
        
        int sum=0;
        
        func(root,sum);
        
        return sum;
        
    }
};