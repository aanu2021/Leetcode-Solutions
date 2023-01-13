class Solution {
public:
    
    typedef long long ll;
    
    bool isBST(TreeNode* &root,ll low,ll high){
        if(!root) return true;
        if(root->val < low || root->val > high) return false;
        bool isLeftBST = isBST(root->left,low,(ll)root->val-1);
        bool isRightBST = isBST(root->right,(ll)root->val+1,high);
        return isLeftBST && isRightBST;
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return isBST(root,(ll)-1e18,(ll)1e18);
    }
};