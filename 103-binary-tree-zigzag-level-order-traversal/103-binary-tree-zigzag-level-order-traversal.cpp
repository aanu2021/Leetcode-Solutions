class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root==NULL){
            
            return {};
            
        }
        
        vector<vector<int>>ans;
        
        int level=0;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty()){
            
            int sz=q.size();
            
            vector<int>temp(sz);
            
            int l=0,r=sz-1;
            
            while(sz--){
                
                auto curr=q.front();
                q.pop();
                
                if(level%2==0){
                    
                    temp[l]=curr->val;
                    l++;
                    
                }
                
                else{
                    
                    temp[r]=curr->val;
                    r--;
                    
                }

                
                if(curr->left){
                    q.push(curr->left);
                }
                
                if(curr->right){
                    q.push(curr->right);
                }
                
            }
            
            ans.push_back(temp);
            
            level++;
            
        }
        
        return ans;
        
    }
};