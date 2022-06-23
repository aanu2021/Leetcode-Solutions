class Solution {
public:
    
    vector<TreeNode*>solve(int n){
        
        vector<TreeNode*>ans;
        
        if(n==1){
            
            return {new TreeNode(0)};
            
        }
        
        else if(n%2==1){
            
            for(int x=0;x<n;x++){
                
                int y=n-x-1;
                
                if(x%2==0 || y%2==0){
                    continue;
                }
                
                for(auto left:solve(x)){
                    
                    for(auto right:solve(y)){
                        
                        TreeNode*node=new TreeNode(0);
                        
                        node->left=left;
                        
                        node->right=right;
                        
                        ans.push_back(node);
                        
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