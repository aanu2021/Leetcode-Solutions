class Solution {
public:
    
    bool func(TreeNode*&root,TreeNode*&target,vector<TreeNode*>&path){
        
        if(root==NULL){
            
            return false;
            
        }
        
        if(root==target){
            
            path.push_back(root);
            
            return true;
            
        }
        
        if(func(root->left,target,path)==true){
            
            path.push_back(root);
            
        }
        
        else if(func(root->right,target,path)==true){
            
            path.push_back(root);
            
        }
        
        return !path.empty();
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==NULL){
            return NULL;
        }
        
        vector<TreeNode*>path1;
        
        vector<TreeNode*>path2;
        
        func(root,p,path1);
        
        func(root,q,path2);
        
//         for(int i=0;i<path1.size();++i){
            
//             cout<<path1[i]->val<<" ";
            
//         }cout<<"\n";
        
//         for(int i=0;i<path2.size();++i){
            
//             cout<<path2[i]->val<<" ";
            
//         }cout<<"\n";
        
           reverse(path1.begin(),path1.end());
        
           reverse(path2.begin(),path2.end());
        
           int sz1=path1.size();
        
           int sz2=path2.size();
        
           int sz=min(sz1,sz2);
        
           int i=0;
         
           for(i=0;i<sz;++i){
               
               if(path1[i]!=path2[i]){
                   
                   break;
                   
               }
               
           }
        
           return path1[i-1]; 
       
    }
};