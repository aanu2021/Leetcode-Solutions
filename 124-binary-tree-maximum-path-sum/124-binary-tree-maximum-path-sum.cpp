class Solution {
public:
    
    int max_path_sum=INT_MIN;
    
    
    int func(TreeNode*&root){
        
        if(root==NULL){
            return 0;
        }
        
        // Case 1 --> Internal path considering current node as the curve point.
        
        int left_path_sum=func(root->left);
        int right_path_sum=func(root->right);
        
        int internal_path=root->val+max(0,left_path_sum)+max(0,right_path_sum);
        
        
        // Case 2 --> Longest Path passing through the current node.
        
        int longest_path=root->val+max(max(0,left_path_sum),max(0,right_path_sum));
        
        max_path_sum=max(max_path_sum,max(internal_path,longest_path));
        
        return longest_path;
        
    }
    
    
    int maxPathSum(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        
        func(root);
        
        return max_path_sum;
        
    }
};