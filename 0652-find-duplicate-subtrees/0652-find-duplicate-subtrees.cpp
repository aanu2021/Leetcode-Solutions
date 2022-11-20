class Solution {
public:
    
    unordered_map<string,vector<TreeNode*>>mapp;
    
    string func(TreeNode*&root){
        
        if(!root) return "";
        
        string str = to_string(root->val);
        
        if(root->left || root->right){
            
            str+='[';
            
            str+=func(root->left);
            
            str+=", ";
            
            str+=func(root->right);
            
            str+=']';
            
        }
        
        mapp[str].push_back(root);
        
        return str;
        
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        if(!root) return {};
        
        func(root);
        
        vector<TreeNode*>vec;
        
        for(auto &itr:mapp){
            if(itr.second.size()>1){
                vec.push_back(itr.second[0]);
            }
        }
        
        return vec;
        
    }
};