
class Solution {
public:
    
    
    
    int kthSmallest(TreeNode* root, int k) {
        
        if(!root){
            return -1;
        }
        
        int cnt=0;
        
        stack<TreeNode*>S;
        
        TreeNode*curr=root;
        
        while(!S.empty() || curr){
            
            while(curr!=NULL){
                
                S.push(curr);
                
                curr=curr->left;
                
            }
            
            curr=S.top();
            S.pop();
            
            cnt++;
            
            if(cnt==k){
                return curr->val;
            }
            
            curr=curr->right;
            
        }
        
        return -1;
        
    }
};