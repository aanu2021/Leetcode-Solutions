class Solution {
public:
    
    /*
    
    Complete Binary Tree --> Combination of a lot of Perfect Binary trees(internal nodes have exactly 2 children && all the leaf nodes must be present at the same level)
    
    T.C : O(logN*logN)
    
    For exploring total height of the tree and findLeftHeight and findRightHeight function they will take O(logN) time in both the cases.
    
    S.C : O(logN)
    
    */
    
    
    int findLeftHeight(TreeNode*&root){
        
        int ht=0;
        
        TreeNode*curr=root;
        
        while(curr){
            ht++;
            curr=curr->left;
        }
        
        return ht;
        
    }
    
    int findRightHeight(TreeNode*&root){
        
        int ht=0;
        
        TreeNode*curr=root;
        
        while(curr){
            ht++;
            curr=curr->right;
        }
        
        return ht;
        
    }
    
    int countNodes(TreeNode* root) {
        
        if(!root){
            return 0;
        }
        
        int lh=findLeftHeight(root);
        int rh=findRightHeight(root);
        
        if(lh==rh){
            return (1<<lh)-1;
        }else{
            return 1+countNodes(root->left)+countNodes(root->right);
        }
        
    }
};