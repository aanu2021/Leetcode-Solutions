class Solution {
public:
    
    bool findPath(TreeNode*root,TreeNode*target,vector<TreeNode*>&path){
        
        if(!root) return false;
        if(root == target){
            path.push_back(root);
            return true;
        }
        if(findPath(root->left,target,path)){
            path.push_back(root);
        }
        else if(findPath(root->right,target,path)){
            path.push_back(root);
        }
        return !path.empty();
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        vector<TreeNode*>path1,path2;
        findPath(root,p,path1);
        findPath(root,q,path2);
        reverse(path1.begin(),path1.end());
        reverse(path2.begin(),path2.end());
        int m = path1.size();
        int n = path2.size();
        int len = min(m,n);
        int i=0;
        for(i=0;i<len;i++){
            if(path1[i] != path2[i]){
                break;
            }
        }
        return path1[i-1];
    }
};