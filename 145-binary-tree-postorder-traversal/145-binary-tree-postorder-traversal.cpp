class Solution {
public:
    
    vector<int> postorderTraversal(TreeNode* root) {
       
        vector<int>postorder;
        
        if(root==NULL){return {};}
        
        stack<TreeNode*>S;
       
        TreeNode*curr=root;
        
        while(curr!=NULL || !S.empty()){
            
            if(curr){
                
                S.push(curr);
                curr=curr->left;
                
            }
            
            else{
                
                TreeNode*temp=S.top()->right;
                
                if(temp==NULL){
                    
                    temp=S.top();
                    S.pop();
                    
                    postorder.push_back(temp->val);
                    
                    while(!S.empty() && temp==S.top()->right){
                        
                        temp=S.top();
                        S.pop();
                        
                        postorder.push_back(temp->val);
                        
                    }
                    
                }else{
                    
                    curr=temp;
                    
                }
                
            }
            
        }
        
        return postorder;
        
    }
};