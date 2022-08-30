class Solution {
public:
    void recoverTree(TreeNode* root) {
        
        if(!root){
            return;
        }
        
        TreeNode*cand1=NULL;
        
        TreeNode*cand2=NULL;
        
        TreeNode*prev=NULL;
        
        TreeNode*curr=root;
        
        while(curr){
            
            if(curr->left==NULL){
                
                if(prev){
                    
                    if(prev->val > curr->val){
                        
                        if(cand1==NULL){
                            cand1=prev;
                        }
                        
                        cand2=curr;
                        
                    }
                    
                }
                
                prev=curr;
                
                curr=curr->right;
                
            }
            
            else{
                
                TreeNode*temp=curr->left;
                
                while(temp && temp->right && temp->right!=curr){
                    temp=temp->right;
                    
                }
                
                if(temp->right==NULL){
                    
                    temp->right=curr;
                    
                    curr=curr->left;
                    
                }
                
                else{
                    
                    if(prev){

                        if(prev->val > curr->val){

                            if(cand1==NULL){
                                cand1=prev;
                            }

                            cand2=curr;

                        }

                    }

                    prev=curr;
                    
                    temp->right=NULL;
                    
                    curr=curr->right;
                    
                }
                
            }
            
        }
        
        swap(cand1->val,cand2->val);
        
    }
};