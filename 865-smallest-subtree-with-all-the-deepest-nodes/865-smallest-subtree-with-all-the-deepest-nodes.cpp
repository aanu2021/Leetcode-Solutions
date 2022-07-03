class Solution {
public:
    
    map<TreeNode*,int>dist;
    
    int deepest_level=-1;
    
    void preprocessing(TreeNode*root,int level){
        
        dist[root]=level;
        
        if(root->left){
            preprocessing(root->left,level+1);
        }
        
        if(root->right){
            preprocessing(root->right,level+1);
        }
        
    }
    
    int cnt=0;
    
    TreeNode*ans=NULL;
    
    int func(TreeNode*root){
        
        if(root==NULL){
            return 0;
        }
        
        int lval=func(root->left);
        int rval=func(root->right);
        
        int curr=lval+rval;
        
        if(dist[root]==deepest_level){
            curr++;
        }
        
        if(curr==cnt){
            
            if(ans==NULL){
               // cout<<"sadad";
                ans=root;
            }
            
        }
        
        return curr;
        
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
        preprocessing(root,0);
        
        int maxlevel=-1;
        
        for(auto itr:dist){
            
            maxlevel=max(maxlevel,itr.second);
            
        }
        
        for(auto itr:dist){
            
            if(itr.second==maxlevel){
                cnt++;
            }
            
        }
        
        deepest_level=maxlevel;
        
       // cout<<deepest_level<<endl;
        
        func(root);
        
        return ans;
        
    }
};