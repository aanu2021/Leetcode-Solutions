class Solution {
public:
    
    map<pair<TreeNode*,pair<bool,bool>>,int>dp;
    
    int func(TreeNode*root,int placedCam,int parentCam){
        
        if(root==NULL){
            
            if(placedCam==1){
                return 1e9;
            }else{
                return 0;
            }
            
        }
        
        if(dp.find({root,{placedCam,parentCam}})!=dp.end()){
            return dp[{root,{placedCam,parentCam}}];
        }
        
        
        int ans=1e9;
        
        
        if(placedCam==0){
            
            if(parentCam==0){
                
                int curr1=func(root->left,1,0)+min(func(root->right,1,0),func(root->right,0,0));
                
                int curr2=func(root->right,1,0)+min(func(root->left,1,0),func(root->left,0,0));
                
                ans=min(ans,min(curr1,curr2));
                
            }
            
            else{
                
                int curr=min(func(root->left,1,0),func(root->left,0,0))+min(func(root->right,1,0),func(root->right,0,0));
                
                ans=min(ans,curr);
                
            }
            
        }
        
        else{
            
            if(parentCam==0){
                
                int curr = 1 + min(func(root->left,1,1),func(root->left,0,1)) + min(func(root->right,1,1),func(root->right,0,1));
                
                ans=min(ans,curr);
                
            }
            
            else{
                
                 int curr = 1 + min(func(root->left,1,1),func(root->left,0,1)) + min(func(root->right,1,1),func(root->right,0,1));
                
                ans=min(ans,curr);
                
            }
            
        }
        
        return dp[{root,{placedCam,parentCam}}] = ans ;
        
    }
    
    int minCameraCover(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        
        int ans=min(func(root,0,0),func(root,1,0));
        
        return ans;
        
    }
};