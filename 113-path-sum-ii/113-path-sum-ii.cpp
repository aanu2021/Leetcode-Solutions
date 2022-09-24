class Solution {
public:
    
    vector<vector<int>>ans;
    
    void func(TreeNode*&root,int targetSum,vector<int>&solution){
        
        if(!root) return;
        
        targetSum-=root->val;
        
        if(!root->left && !root->right){
            
            if(targetSum==0){
                
                solution.push_back(root->val);
                
                ans.push_back(solution);
                
                solution.pop_back();
                
            }
            
            return;
            
        }
        
        solution.push_back(root->val);
        
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