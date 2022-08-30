
class Solution {
public:
    
    int kthSmallest(TreeNode* root, int k) {
        
        if(!root){
            return -1;
        }
        
        vector<int>inorder;
        
        TreeNode*curr=root;
        
        int cnt=1;
        
        int ans=-1;
        
        while(curr!=NULL){
            
            if(curr->left==NULL){
                
                if(cnt==k){
                    
                    ans=curr->val;
                    
                }
                
                cnt++;
                
                curr=curr->right;
                
            }
            
            else{
                
                TreeNode*prev=curr->left;
                
                while(prev!=NULL && prev->right!=NULL && prev->right!=curr){
                    
                    prev=prev->right;
                    
                }
                
                if(prev->right!=curr){
                    
                    prev->right=curr;
                    
                    curr=curr->left;
                    
                }
                
                else{
                    
                    prev->right=NULL;
                    
                    if(cnt==k){
                        
                        ans=curr->val;
                        
                    }
                    
                    cnt++;
                    
                    curr=curr->right;
                    
                }
                
            }
            
        }
        
        return ans;
        
    }
};