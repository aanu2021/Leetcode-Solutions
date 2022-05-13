class Solution {
public:
    Node* connect(Node* root) {
        
        if(root==NULL){
            return root;
        }
        
        if(root->left!=NULL && root->right!=NULL){
            root->left->next=root->right;
        }
        
        if(root->right!=NULL && root->next!=NULL){
            root->right->next=root->next->left;
        }
        
        connect(root->left);
        connect(root->right);
        
        return root;
        
    }
};