class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        if(!root){
            return {};
        }
        
        TreeNode*curr=root;
        
        stack<TreeNode*>S;
        
        vector<int>ans;
        
        
        while(curr!=NULL || !S.empty()){
            
            if(curr!=NULL){
                
                S.push(curr);
                curr=curr->left;
                
            }
            
            else{
                
                curr=S.top();
                S.pop();
                        
                ans.push_back(curr->val);
                
                curr=curr->right;
                
            }
            
        }
        
        return ans;
        
    }
};