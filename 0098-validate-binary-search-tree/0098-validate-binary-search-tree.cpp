class Solution {
public:
    
    typedef long long ll;
    
    bool func(TreeNode*&root,ll mini,ll maxi){
        if(!root) return true;
        if(root->val < mini || root->val > maxi) return false;
        return func(root->left,mini,(ll)root->val-1) && func(root->right,(ll)root->val+1,maxi);
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return func(root,-1e10,1e10);
    }
};