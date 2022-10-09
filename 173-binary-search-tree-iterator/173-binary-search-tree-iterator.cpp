/*

Approach : Iterative Inorder Traversal (Using a Stack)

Algorithm :

1. At any point of time , we need to find out the minimum valued node among the present ones.

2. Again , we know inorder traversal of a BST gives a sorted array .

3. Using point (2) , one approach would be initialize an vector and store the node values inside the BST by traversing it in an inorder fashion , and make a pointer to iterate through the values from the smallest to the largest.

4. But for these approach , T.C : O(N) , S.C : O(N)

5. Now , the question arises , can we reduce the space complexity , indeed we can.

6. If we maintain a stack and store the Tree Nodes in an inorder fashion then in the worst case 'H' number of nodes will be present inside the stack.

7. Push all the left most nodes from the current node , then start popping them , after popping a node , if we find that some nodes are present in ots right subtree , then starts exploring them , by pushing All left most nodes of that right subtree.

8. For these approach , T.C : O(N) , S.C : O(H)

*/


class BSTIterator2 {
public:
    
    stack<TreeNode*>S;
    
    BSTIterator2(TreeNode* root) {
        
        pushAll(root);
        
    }
    
    void pushAll(TreeNode*root){
        
        if(!root) return;
        
        while(root){
            
            S.push(root);
            root = root->left;
            
        }
        
    }
    
    int next() {
        
        TreeNode*curr = S.top();
        S.pop();
        
        int value = curr->val;
        
        if(curr->right){
            
            pushAll(curr->right);
            
        }
        
        return value;
        
    }
    
    bool hasNext() {
        
        return !S.empty();
        
    }
};

class BSTIterator {
public:
    
    TreeNode*curr;
    
    BSTIterator(TreeNode* root) {
        
        curr = root;
        
    }
   
    
    int next() {
        
        while(curr){
            
            if(curr->left==NULL){
                
                int value = curr->val;
                
                curr = curr->right;
                
                return value;
                
            }
            
            else{
                
                TreeNode*prev = curr->left;
                
                while(prev && prev->right && prev->right!=curr){
                    
                    prev = prev->right;
                    
                }
                
                if(prev->right==NULL){
                    
                    prev->right = curr;
                    curr = curr->left;
                    
                }
                
                else{
                    
                    int value = curr->val;
                    
                    prev->right = NULL;
                    
                    curr = curr->right;
                    
                    return value;
                    
                }
                
            }
            
        }
        
        return -1;
        
    }
    
    bool hasNext() {
        
        return curr;
        
    }
};

