class BSTIterator {
public:
    
    stack<TreeNode*>S;
    
    BSTIterator(TreeNode* root) {
        
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

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */