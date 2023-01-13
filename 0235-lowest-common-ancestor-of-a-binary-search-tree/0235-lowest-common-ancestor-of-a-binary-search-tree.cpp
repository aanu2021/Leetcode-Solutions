class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val) swap(p,q);
        if(!root) return NULL;
        while(root){
            if(root->val >= p->val && root->val <= q->val){
                return root;
            }
            else if(root->val >= p->val && root->val >= q->val){
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        return NULL;
    }
};