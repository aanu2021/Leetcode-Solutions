class Solution {
public:
    
    bool func(TreeNode*&root,TreeNode*&target,vector<TreeNode*>&psf){
        
        if(!root){
            return false;
        }
        
        psf.push_back(root);
        
        if(root==target){
            return true;
        }
        
        if(func(root->left,target,psf) || func(root->right,target,psf)){
            
            return true;
            
        }
        
        psf.pop_back();
        
        return false;
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root){
            return NULL;
        }
        
        vector<TreeNode*>path1,path2;
        
        func(root,p,path1);
        
        func(root,q,path2);
        
        int i=0;
        
        int sz1=path1.size();
        int sz2=path2.size();
        
        int sz=min(sz1,sz2);
        
        for(i=0;i<sz;++i){
            if(path1[i]!=path2[i]){
                break;
            }
        }
        
        return path1[i-1];
        
    }
};