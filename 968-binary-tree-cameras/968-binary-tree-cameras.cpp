//Approach : DP on Trees

class Solution {
public:
    
    map<pair<TreeNode*,pair<bool,bool>>,int>dp;
    
    int func(TreeNode*root,int placed,int parentCam){
        
        if(root==NULL){
            
            if(placed==1){
                return 1e9;
            }else{
                return 0;
            }
           
        }
        
        if(dp.find({root,{placed,parentCam}})!=dp.end()){
            return dp[{root,{placed,parentCam}}];
        }
        
        int ans=1e9;
        
        if(placed==0){
            
            if(parentCam==0){
                
                int curr1=func(root->left,1,0)+min(func(root->right,1,0),func(root->right,0,0)) ;
                
                int curr2=func(root->right,1,0)+min(func(root->left,1,0),func(root->left,0,0));
                
                ans = min(curr1,curr2);
                
            }
            
            else{
                
                ans = min(func(root->left,0,0),func(root->left,1,0)) + min(func(root->right,0,0),func(root->right,1,0));
                
            }
            
        }
        
        else{
            
            if(parentCam==0){
                
               ans = 1 + min(func(root->left,0,1),func(root->left,1,1)) + min(func(root->right,0,1),func(root->right,1,1));   
                
            }
            
            else{
                
                ans = 1 + min(func(root->left,0,1),func(root->left,1,1)) + min(func(root->right,0,1),func(root->right,1,1));
                
            }
            
        }
        
        return dp[{root,{placed,parentCam}}]=ans;
        
    }
    
    int minCameraCover(TreeNode* root) {
        
        if(root==NULL)return 0;
        
        if(root==NULL && root->left==NULL && root->right==NULL)return 1;
        
        
       /*  
       
       
       dp[u][a][b] --> gives us the minimum number of cameras required to monitor the entire subtree rooted at vertex u , given that a(0/1) be the state of placing a camera or not , and b(0/1) be the state of presence of a camera at its parent node.
       
       
       */
        
        
        int ans=min(func(root,1,0),func(root,0,0));
        
        return ans;
        
    }
};