
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
        
       flatten2(root->right);
       flatten2(root->left);
        
       root->right = prevNode;
       root->left = NULL;
       prevNode = root; 
        
    }
    
    
    void flatten(TreeNode* root){
        
        if(!root) return;
        
        stack<TreeNode*>S;
        S.push(root);
        
        while(!S.empty()){
            auto curr = S.top(); S.pop();
            if(curr->right){
                S.push(curr->right);
            }
            if(curr->left){
                S.push(curr->left);
            }
            if(!S.empty()) curr->right = S.top();
            curr->left = NULL;
        }
        
    }
    
};