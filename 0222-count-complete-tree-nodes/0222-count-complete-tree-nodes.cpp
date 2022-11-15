class Solution {
public:
    
    /*
    
    Complete Binary Tree --> Combination of a lot of Perfect Binary trees(internal nodes have exactly 2 children && all the leaf nodes must be present at the same level)
    
    T.C : O(logN*logN)
    
    For exploring total height of the tree and findLeftHeight and findRightHeight function they will take O(logN) time in both the cases.
    
    S.C : O(logN)
    
    */
    
    
    int left_height(TreeNode*&root){
        if(!root) return 0;
        TreeNode*curr = root;
        int ht = 0;
        while(curr){
            ht++;
            curr = curr->left;
        }
        return ht;
    }
    
    int right_height(TreeNode*&root){
        if(!root) return 0;
        TreeNode*curr = root;
        int ht = 0;
        while(curr){
            ht++;
            curr = curr->right;
        }
        return ht;
    }
    
    int countNodes(TreeNode* root) {
        
        if(!root) return 0;
        
        int lht = left_height(root);
        int rht = right_height(root);
        
        if(lht==rht){
            return pow(2,lht)-1;
        }else{
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
        
    }
};