class Solution {
public:
    
    map<pair<pair<TreeNode*,int>,int>,int>dp;
    
    int func(TreeNode*&root,int parentCam,int placedCam){
        
        if(!root){
            
            if(placedCam==0){
                return 0;
            }
            
            else{
                return 1e9;
            }
            
        }
        
        if(dp.find({{root,parentCam},placedCam})!=dp.end()){
            
            return dp[{{root,parentCam},placedCam}];
            
        }
        
        
        int currval=1e9;
        
        if(parentCam==0){
            
            if(placedCam==0){
                
                currval=min({func(root->left,0,1)+func(root->right,0,1),func(root->left,0,1)+func(root->right,0,0),func(root->left,0,0)+func(root->right,0,1)});
                
            }
            
            else{
                
                currval=1 + min(func(root->left,1,0),func(root->left,1,1)) + min(func(root->right,1,0),func(root->right,1,1));
                
            }
            
        }
        
        else{
            
            if(placedCam==0){
                
                 currval=min({func(root->left,0,1)+func(root->right,0,1),func(root->left,0,1)+func(root->right,0,0),func(root->left,0,0)+func(root->right,0,1),func(root->left,0,0)+func(root->right,0,0)});
                
            }
            
            else{
                
                  currval=1 + min(func(root->left,1,0),func(root->left,1,1)) + min(func(root->right,1,0),func(root->right,1,1));
                
            }
            
        }
        
        return dp[{{root,parentCam},placedCam}] = currval;
        
    }
    
    int minCameraCover(TreeNode* root) {
        
        if(!root){
            return 0;
        }
        
        int ans=min(func(root,0,1),func(root,0,0));
        
        return ans;
        
    }
};