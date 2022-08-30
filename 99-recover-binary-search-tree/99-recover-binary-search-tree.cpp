class Solution {
public:
    
    vector<TreeNode*>vec;
    
    void inorder(TreeNode*&root){
        
        if(!root){
            return;
        }
        
        inorder(root->left);
        
        vec.push_back(root);
        
        inorder(root->right);
        
    }
    
    void recoverTree(TreeNode* root) {
        
        if(!root){
            return;
        }

        inorder(root);
        
        TreeNode*prev=NULL;
        TreeNode*next=NULL;
        
        for(int i=0;i<vec.size()-1;++i){
            
            if(vec[i]->val > vec[i+1]->val){
                
                if(prev==NULL){
                    prev=vec[i];
                }
                
                next=vec[i+1];
                
            }
            
        }
        
        
        swap(prev->val,next->val);
        
    }
};