
class Solution {
public:
    
    /*
    
    T.C : O(N*N)
    S.C : O(H)
    
    */
    
    void flatten3(TreeNode* root) {
       
        if(!root) return;
        
        if(!root->left && !root->right) return;
        
        flatten3(root->left);
        flatten3(root->right);
        
        TreeNode*leftChild = root->left;
        TreeNode*rightChild = root->right;
        
        root->left = NULL;
        root->right = leftChild;
        TreeNode*curr = root;
        while(curr && curr->right){
            curr = curr->right;
        }
        curr->right = rightChild;
        
    }
    
    
    /*
    
    T.C : O(N)
    S.C : O(H)
    
    */
    
    TreeNode * prevNode = NULL;
    
    void flatten2(TreeNode* root) {
       
        if(!root) return;
        
        flatten(root->right);
        flatten(root->left);
        
        root->right = prevNode;
        root->left = NULL;
        prevNode = root;
        
    }
    
    /*
    
    T.C : O(N)
    S.C : O(1)
    
    root , left_subtree , right_subtree
    
    */
    
    void flatten(TreeNode* root){
        
        if(!root) return;
        
        TreeNode * curr = root;
        
        while(curr){
            if(curr->left){
                TreeNode * prev = curr->left;
                while(prev && prev->right){
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
        
    }
    
};