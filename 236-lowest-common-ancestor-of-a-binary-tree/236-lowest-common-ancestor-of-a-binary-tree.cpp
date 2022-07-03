class Solution {
public:
    
    
    bool func(TreeNode*root,TreeNode* target, vector<TreeNode*>&path){
        
        if(root==NULL){
            return false;
        }
        
        if(root==target){
            path.push_back(root);
            return true;
        }
        
        
        if(func(root->left,target,path)){
            
            path.push_back(root);
            
        }
        
        else if(func(root->right,target,path)){
            
            path.push_back(root);
            
        }
        
        
        if(!path.empty()){
            return true;
        }else{
            return false;
        }
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode*>path1;
        
        vector<TreeNode*>path2;
        
        func(root,p,path1);
        
        func(root,q,path2);
        
        reverse(path1.begin(),path1.end());
        
        reverse(path2.begin(),path2.end());
        
        int sz1=path1.size();
        
        int sz2=path2.size();
        
        int i=0;
        
        for(i=0;i<min(sz1,sz2);++i){
            
            if(path1[i]!=path2[i]){
                
                break;
                
            }
            
        }
        
      //  cout<< path1[i-1] <<endl;
        
//         for(int i=0;i<path1.size();++i){
//             cout<<path1[i]<<" ";
//         }cout<<"\n";
        
//         for(int i=0;i<path2.size();++i){
//             cout<<path2[i]<<" ";
//         }cout<<"\n";
        
        return path1[i-1];
        
    }
};