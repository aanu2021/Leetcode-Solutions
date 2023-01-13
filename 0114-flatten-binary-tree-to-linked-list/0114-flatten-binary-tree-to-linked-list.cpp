
class Solution {
public:
    
    /*
    
    T.C : O(N*N)
    S.C : O(H)
    
    */
    
    void flatten2(TreeNode* root) {
       
        if(!root) return;
        
        if(!root->left && !root->right) return;
        
        flatten2(root->left);
        flatten2(root->right);
        
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
    
    TreeNode * prevNode = NULL;
    
    void flatten(TreeNode* root) {
       
       if(!root) return;
        
       flatten(root->right);
       flatten(root->left);
        
       root->right = prevNode;
       root->left = NULL;
       prevNode = root; 
        
    }
    
};