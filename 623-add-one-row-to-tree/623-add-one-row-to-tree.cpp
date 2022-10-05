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
    
    TreeNode*addRow(TreeNode*&root,int val,int d,int depth){
        
       if(!root) return NULL; 
        
       if(d==depth-1){
           
           TreeNode*tempLeft=root->left;
           TreeNode*tempRight=root->right;
           
           root->left = new TreeNode(val);
           root->right = new TreeNode(val);
           
           root->left->left=tempLeft;
           root->right->right=tempRight;
           
           return root;
           
       }
        
       else{
           
           root->left = addRow(root->left,val,d+1,depth);
           root->right = addRow(root->right,val,d+1,depth);
           
           return root;
           
       }  
        
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth==1){
            
            TreeNode*node=new TreeNode(val);
            
            node->left = root;
            node->right = NULL;
            
            return node;
            
        }
        
        root=addRow(root,val,1,depth);
        
        return root;
        
    }
};