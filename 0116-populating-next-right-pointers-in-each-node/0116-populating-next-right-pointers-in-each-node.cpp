class Solution {
public:
    Node* connect(Node* root) {
        
        if(!root) return NULL;
        
        if(root->left && root->right){
            
            root->left->next = root->right;
            
        }
        
        if(root->right && root->next){
            
            root->right->next = root->next->left;
            
        }
        
        connect(root->left);
        connect(root->right);
        
        return root;
        
    }
};