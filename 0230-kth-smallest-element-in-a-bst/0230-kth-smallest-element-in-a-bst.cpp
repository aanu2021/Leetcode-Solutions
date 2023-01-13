class Solution {
public:
    
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        int ans = -1;
        while(root){
            if(root->left == NULL){
                k--;
                if(k==0) ans = root->val;
                root = root->right;
            }
            else{
                TreeNode* prev = root->left;
                while(prev && prev->right && prev->right != root){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = root;
                    root = root->left;
                }
                else{
                    k--;
                    if(k==0) ans = root->val;
                    prev->right = NULL;
                    root = root->right;
                }
            }
        }
        return ans;
    }
};