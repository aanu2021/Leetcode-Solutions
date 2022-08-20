class Solution {
public:
    
    vector<int>ans;
    
    void recursion(TreeNode*&root,int lvl,int *maxlevel){
        
        if(root==NULL){
            return ;
        }
        
        if(lvl>*maxlevel){
            ans.push_back(root->val);
            *maxlevel=lvl;
        }
        
        recursion(root->right,lvl+1,maxlevel);
        recursion(root->left,lvl+1,maxlevel);
        
    }
    
    vector<int> rightSideView(TreeNode* root) {
        
        if(root==NULL){
            return {};
        }
        
        int maxlevel=0;
        
        recursion(root,1,&maxlevel);
        
        return ans;
        
    }
};