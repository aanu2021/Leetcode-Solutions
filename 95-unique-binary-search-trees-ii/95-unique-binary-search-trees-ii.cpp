class Solution {
public:
    
    vector<TreeNode*>func(int start,int end){
        
        if(start>end){
            return {NULL};
        }
        
        if(start==end){
            return {new TreeNode(start)};
        }
        
        vector<TreeNode*>res;
        
        for(int i=start;i<=end;i++){
            
            vector<TreeNode*>left=func(start,i-1);
            vector<TreeNode*>right=func(i+1,end);
            
            for(auto l:left){
                
                for(auto r:right){
                    
                    TreeNode*node=new TreeNode(i);
                    node->left=l;
                    node->right=r;
                    
                    res.push_back(node);
                    
                }
                
            }
            
        }
        
        return res;
        
    }
    
    vector<TreeNode*> generateTrees(int n) {
        
        return func(1,n);
        
    }
};