class Solution {
public:
    
    vector<int>ans;
    
    void dfs(TreeNode*&root,int lvl,int &maxlevel){
        
        if(!root){
            return;
        }
        
        if(lvl>maxlevel){
            
            maxlevel=lvl;
            
            ans.push_back(root->val);
            
        }
        
        if(root->right){
            
            dfs(root->right,lvl+1,maxlevel);
            
        }
        
        if(root->left){
            
            dfs(root->left,lvl+1,maxlevel);
            
        }
        
    }
    
    vector<int> rightSideView(TreeNode* root) {
        
        if(!root){
            return {};
        }
        
        int maxlevel=-1;
        
        dfs(root,0,maxlevel);
        
        return ans;
        
    }
};