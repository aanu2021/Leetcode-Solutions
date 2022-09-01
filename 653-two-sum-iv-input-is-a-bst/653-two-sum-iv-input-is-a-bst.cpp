class BST_iterator{
    
  private:
    
    stack<TreeNode*>S;
    bool reverse;
    
  public:
    
    BST_iterator(TreeNode*root,bool isreverse){
        
        reverse=isreverse;
        pushAll(root);
        
    }
    
    void pushAll(TreeNode*root){
        
        if(!root){
            return;
        }
        
        while(root){
            
            S.push(root);
            
            if(!reverse){
                root=root->left;
            }else{
                root=root->right;
            }
            
        }
        
    }
    
    int next(){
        
        auto node=S.top();
        S.pop();
        
        int value=node->val;
        
        if(!reverse){
            pushAll(node->right);
        }else{
            pushAll(node->left);
        }
        
        return value;
        
    }
    
    bool hasnext(){
        
        return !S.empty();
        
    }
    
    
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        if(!root){
            return false;
        }
        
        BST_iterator l(root,false);
        BST_iterator r(root,true);
        
        int i=l.next();
        int j=r.next();
        
        while(i<j){
            
            int sum=(i+j);
            
            if(sum==k){
                return true;
            }
            
            else if(sum>k){
                j=r.next();
            }
            
            else{
                i=l.next();
            }
            
        }
        
        return false;
        
    }
};