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
        
        while(root!=NULL){
            
            S.push(root);
            
            if(!reverse){
                root=root->left;
            }else{
                root=root->right;
            }
            
        }
        
    }
    
    int next(){
        
        auto curr=S.top();
        S.pop();
        
        int value=curr->val;
        
        if(!reverse){
            
            pushAll(curr->right);
            
        }
        
        else{
            
            pushAll(curr->left);
            
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
        
        BST_iterator l(root,false);
        
        BST_iterator r(root,true);
        
        int i=l.next();
        
        int j=r.next();
        
        while(i<j){
            
            if(i+j==k){
                return true;
            }
            
            else if(i+j<k){
                i=l.next();
            }
            
            else{
                j=r.next();
            }
            
        }
        
        return false;
        
    }
};