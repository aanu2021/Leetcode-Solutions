class Solution {
public:
    
    TreeNode* func(TreeNode* &root, int target){
        if(!root) return NULL;
        // Leaf Node
        if(!root->left && !root->right){
            return root->val == target ? NULL : root;
        }
        // Non-Leaf Node
        else{
            TreeNode * leftSubTree = func(root->left, target);
            TreeNode * rightSubTree = func(root->right, target);
            // Update Left subtree, Right subtree
            root->left = leftSubTree;
            root->right = rightSubTree;
            
            if(!leftSubTree && !rightSubTree){
                return root->val == target ? NULL : root;
            }
            else{
                return root;
            }
        }       
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
       return func(root, target);
    }
};