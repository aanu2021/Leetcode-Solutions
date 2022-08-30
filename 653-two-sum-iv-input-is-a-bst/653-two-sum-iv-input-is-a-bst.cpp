class BST_Iterator{
    
  private:
    
    stack<TreeNode*>S;
    
    bool reverse;
    
  public:
    
    BST_Iterator(TreeNode*root,bool isreverse){
        
        reverse=isreverse;
        
        pushAll(root);
        
    }
    
    void pushAll(TreeNode*root){
        
        while(root){
            
            S.push(root);
            
            if(reverse){
                root=root->right;
            }
            
            else{
                root=root->left;
            }
            
        }
        
    }
    
    int next(){
        
        auto node=S.top();
        S.pop();
        
        int value=node->val;
        
        if(!reverse){
            
            pushAll(node->right);
            
        }
        
        else{
            
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
        
        BST_Iterator l(root,false);
        
        BST_Iterator r(root,true);
        
        int i=l.next();
        
        int j=r.next();

        
        while(i<j){
            
            if(i+j==k){
                return true;
            }
            
            if(i+j<k){
                i=l.next();
            }
            
            else{
                j=r.next();
            }
            
        }
        
        return false;
        
    }
};