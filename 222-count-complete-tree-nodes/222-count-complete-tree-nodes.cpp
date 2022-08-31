class Solution {
public:
    
    /*
    
    Complete Binary Tree --> Combination of a lot of Perfect Binary trees(internal nodes have exactly 2 children && all the leaf nodes must be present at the same level)
    
    T.C : O(logN*logN)
    
    For exploring total height of the tree and findLeftHeight and findRightHeight function they will take O(logN) time in both the cases.
    
    S.C : O(logN)
    
    */
    
    
    
    int left_height(TreeNode*&root){
        
        if(!root){
            return 0;
        }
        
        TreeNode*curr=root;
        
        int ht=0;
        
        while(curr){
            
            curr=curr->left;
            
            ht++;
            
        }
        
        return ht;
        
    }
    
    int right_height(TreeNode*&root){
        
        if(!root){
            return 0;
        }
        
        TreeNode*curr=root;
        
        int ht=0;
        
        while(curr){
            
            curr=curr->right;
            
            ht++;
            
        }
        
        return ht;
        
    }
    
    int countNodes(TreeNode* root) {
        
        if(!root){
            return 0;
        }
        
        int lh=left_height(root);
        int rh=right_height(root);
        
        if(lh==rh){
            
            return (1<<lh)-1;
            
        }
        
        else{
            
            return 1 + countNodes(root->left) + countNodes(root->right);
            
        }
        
    }
};