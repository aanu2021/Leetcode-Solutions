/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int level=-1;
    
    int sum=0;
   
    int find_level(TreeNode*root){
        
        if(root==NULL){
            return 0;
        }
        
        return 1+max(find_level(root->left),find_level(root->right));
        
    }
    
    void func(TreeNode*root,int lvl){
        
       if(root==NULL){
           return ;
       }
        
        if(lvl==level-1){
            sum+=root->val;
        }
        
        func(root->left,lvl+1);
        func(root->right,lvl+1);
        
    }
    
    int deepestLeavesSum(TreeNode* root) {
        
        level=find_level(root);
        
        cout<<level<<endl;
        
        func(root,0);
        
        return sum;
        
    }
};