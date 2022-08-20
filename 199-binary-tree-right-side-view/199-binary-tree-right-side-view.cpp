class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        if(root==NULL){
            return {};
        }
        
        vector<int>ans;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty()){
            
            int sz=q.size();
            
            int right_value=-1;
            
            while(sz--){
                
                auto node=q.front();
                q.pop();
                
                right_value=node->val;
                
                if(node->left){
                    q.push(node->left);
                }
                
                if(node->right){
                    q.push(node->right);
                }
                
            }
            
            ans.push_back(right_value);
            
        }
        
        return ans;
        
    }
};