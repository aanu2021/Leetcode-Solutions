class BSTIterator{
    
    private:
    
    stack<TreeNode*>S;
    bool reverse;
    
    public:
    
    BSTIterator(TreeNode*root,bool isReverse){
        
        reverse = isReverse;
        
        pushAll(root);
        
    }
    
    void pushAll(TreeNode*root){
        
        if(!root) return;
        
        while(root){
            
            S.push(root);
            
            if(reverse){
                root=root->right;
            }else{
                root=root->left;
            }
            
        }
        
    }
    
    int next(){
        
        TreeNode * curr = S.top();
        S.pop();
        
        int value = curr->val;
        
        if(reverse){
            
            pushAll(curr->left);
            
        }
        
        else{
            
            pushAll(curr->right);
            
        }
        
        return value;
        
    }
    
    bool hasNext(){
        
        return !S.empty();
        
    }
    
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        if(!root) return false;
        
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        
        int i = l.next();
        int j = r.next();
        
        while(i<j){
            
            if(i+j==k){
                return true;
            }
            
            else if(i+j>k){
                j = r.next();
            }
            
            else{
                i = l.next();
            }
            
        }
        
        return false;
        
    }
};