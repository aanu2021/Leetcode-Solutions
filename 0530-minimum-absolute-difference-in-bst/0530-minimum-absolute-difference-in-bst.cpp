// Morris Inorder Traversal...

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        
        if(!root) return 0;
        
        int minDiff = INT_MAX;
        int prevVal = -1;
        
        while(root){
            
            // Leaf Node
            if(!root->left){
                if(prevVal != -1){
                    minDiff = min(minDiff,root->val - prevVal);
                }
                prevVal = root->val;
                root = root->right;
            }
            // Not a Leaf Node
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
                    prev->right = NULL;
                    if(prevVal != -1){
                       minDiff = min(minDiff,root->val - prevVal);
                    }
                    prevVal = root->val;
                    root = root->right;
                }
                
            }
            
        }
        
        return minDiff;
        
    }
};