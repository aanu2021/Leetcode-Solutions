class Solution {
public:
    
    /*
    
    But in the above mentioned approach , we are not able to use
    thr super cool properties of BST not even a single time ,
    can we use that to reduce time and space complexities......
    
    Definitely yes , look for a valid BST , every node of that
    BST should maintain a property ,
    
       a. node->val > node->left->val (all nodes in left sub)
       b. node->val < node->right->val (all nodes in right sub)
       
       
        Now in these question , there are given that all the
        node values are unique , and node p and q should exist 
        in the BST, that clearly implies , if we are at node (u)
        , and never ever explore (p) and (q) beforehand , then 
        there are three possibilities of exploring them 
        afterwards ------>
        
        
        Case 1 --> (p->val < node->val) && (q->val < node->val)
        
        Case 2 --> (p->val > node->val) && (q->val > node->val)
        
        Case 3 --> All the other cases
        
        
        Now if we observe carefully , we can figure out that
        
        For case1 , node p and q should lie in the left
        subtree of the current node , that is why the ancestor 
        might be current root node or some node in its left sub.
        
        For case2 , node p and q should lie in the right
        subtree of the current node , that is why the ancestor
    might be current root node or some node in its right sub.
    
        For case3 , ancestor would ne definitely the current
        root node.
    
    */
    
    
    /*
    
    Time Complexity : O(H) --> where H is the height of the BST
    
        Average Case : O(logN) [Balanced BST]
        Worst Case   : O(N)    [Skewed BST]
    
    Space Complexity : Recursion Stack Space (more or less O(H))
    
       Average Case : O(logN)  [Balanced BST]
       Worst Case   : O(N)     [Skewed BST]
    
    */
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // Handling Case1
        
        if((root->val>p->val) && (root->val>q->val)){
            
            return lowestCommonAncestor(root->left,p,q);
            
        }
        
        // Handling Case2
        
        if((root->val<p->val) && (root->val<q->val)){
            
            return lowestCommonAncestor(root->right,p,q);
            
        }
        
        // Handling Other Cases
        
        return root;
        
    }
};