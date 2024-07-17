class Solution {
public:
    
    unordered_set<int>S;
    vector<TreeNode*>result;
    
    void func(TreeNode* &root){
        if(!root) return;
        func(root->left);
        func(root->right);
        if(S.find(root->val) != S.end()){
            if(root->left) result.push_back(root->left);
            if(root->right) result.push_back(root->right);
            root = NULL;
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        if(!root) return {};
        
        S.clear();
        result.clear();
        
        for(int &ele : to_delete) S.insert(ele);
        
        func(root);
        
        if(root) result.push_back(root);
        
        return result;
    }
};