class Solution {
public:
    
    vector<vector<int>>ans;
    
    void func(TreeNode*&root,int targetSum,vector<int>&solution){
        
        if(!root) return;
        
        targetSum-=root->val;
        
        solution.push_back(root->val);
        
        if(!root->left && !root->right && targetSum==0){
            ans.push_back(solution);
        }
        
        func(root->left,targetSum,solution);
        
        func(root->right,targetSum,solution);
        
        solution.pop_back();
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        if(!root) return {};
        
        vector<int>solution;
        
        func(root,targetSum,solution);
        
        return ans;
        
    }
};