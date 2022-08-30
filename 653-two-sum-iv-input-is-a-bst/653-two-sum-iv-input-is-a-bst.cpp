class Solution {
public:
    
    map<int,int>mapp;
    
    bool flag=false;
    
    void inorder(TreeNode*&root,int target){
        
        if(!root || flag){
            return;
        }
        
        inorder(root->left,target);
        
        mapp[root->val]++;
        
        int required=target-root->val;
        
        if(required!=root->val && mapp[required]>0){
            
            flag=true;
            return;
            
        }
        
        inorder(root->right,target);
        
    }
    
    bool findTarget(TreeNode* root, int target){
        
        inorder(root,target);
        
        return flag;
        
    }
};