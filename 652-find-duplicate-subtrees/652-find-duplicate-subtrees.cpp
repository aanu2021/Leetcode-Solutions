class Solution {
public:
    
    unordered_map<string,vector<TreeNode*>>mp;
    
    string func(TreeNode*root){
        
        if(root==NULL){
            return "";
        }
        
        string s="(" + func(root->left) + to_string(root->val) + func(root->right) + ")";
        
        mp[s].push_back(root);
        
        return s;
        
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        if(root==NULL){
            return {};
        }
        
        func(root);
        
        vector<TreeNode*>ans;
        
        for(auto itr:mp){
            
            if(itr.second.size()>1){
                
                ans.push_back(itr.second[0]);
                
            }
            
        }
        
        return ans;
        
    }
};