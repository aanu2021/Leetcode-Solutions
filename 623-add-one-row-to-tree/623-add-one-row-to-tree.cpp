/*

Time Complexity  : O(N)
Space Complexity : O(H)
Approach : Recursive DFS

*/


class Solution {
public:
    
    TreeNode*addRow(TreeNode*&root,int val,int d,int depth){
        
       if(!root) return NULL; 
        
       // When the next level == depth // 
        
       if(d==depth-1){
           
           TreeNode*tempLeft = root->left;
           TreeNode*tempRight = root->right;
           
           root->left = new TreeNode(val);
           root->right = new TreeNode(val);
           
           root->left->left = tempLeft;
           root->right->right = tempRight;
           
           return root;
           
       }
        
        // Otherwise do a simple DFS Traversal //
        
       else{
           
           root->left = addRow(root->left,val,d+1,depth);
           root->right = addRow(root->right,val,d+1,depth);
           
           return root;
           
       }  
        
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        // Edge Case //
        
        if(depth==1){
            
            TreeNode*node=new TreeNode(val);
            
            node->left = root;
            node->right = NULL;
            
            return node;
            
        }
        
        // Recursion Call //
        
        root=addRow(root,val,1,depth);
        
        return root;
        
    }
};