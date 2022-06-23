class Solution {
public:
    
    vector<TreeNode*>solve(int n){
        
        vector<TreeNode*>ans;
        
        if(n==1){
            
            return {new TreeNode(0)};
            
        }
        
        else if(n%2==1){
            
            for(int x=0;x<n;x++){
                
                int y=n-1-x;
                
                for(auto left:solve(x)){
                    
                    for(auto right:solve(y)){
                        
                        TreeNode*curr=new TreeNode(0);
                        
                        curr->left=left;
                        curr->right=right;
                        
                        ans.push_back(curr);
                        
                    }
                    
                }
                
            }
            
        }
        
        return ans;
        
        
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        
        if(n%2==0){
            return {};
        }
        
        return solve(n);
        
    }
};