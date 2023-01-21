class BSTIterator {
public:
    
    TreeNode * curr;
    
    BSTIterator(TreeNode* root) {
        curr = root;
    }
    
    int getNext(){
        while(curr){
            if(curr->left == NULL){
                int value = curr->val;
                curr = curr->right;
                return value;
            }
            else{
                TreeNode * prev = curr->left;
                while(prev && prev->right && prev->right != curr){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    int value = curr->val;
                    curr = curr->right;
                    return value;
                }
            }
        }
        return -1;
    }
    
    int next() {
        return getNext();
    }
    
    bool hasNext() {
        return (curr != NULL);
    }
};
