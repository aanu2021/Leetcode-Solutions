class Solution {
public:
    
    bool func(TreeNode*root,TreeNode*target,vector<TreeNode*>&path){
        
        if(root==NULL){
            
            return false;
            
        }
        
        if(root==target){
            
            path.push_back(root);
            
            return true;
            
        }
        
        if(root->left && func(root->left,target,path)){
            
            path.push_back(root);
            
        }
        
        else if(root->right && func(root->right,target,path)){
            
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
        
//         cout<<path1.size()<<"\n";
        
//         cout<<path2.size()<<"\n";
        
        int sz1=path1.size();
        
        int sz2=path2.size();
        
        reverse(path1.begin(),path1.end());
        
        reverse(path2.begin(),path2.end());
        
//         for(int i=0;i<sz1;++i){
//             cout<<path1[i]->val<<" ";
//         }cout<<"\n";
        
//         for(int i=0;i<sz2;++i){
//             cout<<path2[i]->val<<" ";
//         }cout<<"\n";
        
        int i=0;
        
        for(i=0;i<min(sz1,sz2);++i){
            
            if(path1[i]!=path2[i]){
                break;
            }
            
        }
        
        return path1[i-1];

        
    }
};