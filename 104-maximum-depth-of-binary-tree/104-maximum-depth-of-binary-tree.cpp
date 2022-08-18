class Solution {
public:
    
    int depth(TreeNode*&root){
        
        if(root==NULL){
            return 0;
        }
        
        int ld=depth(root->left);
        int rd=depth(root->right);
        
        return 1+max(ld,rd);
        
    }
    
    int depth2(TreeNode*&root){
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        int level=0;
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                auto node=q.front();
                q.pop();
                
                if(node->left){
                    q.push(node->left);
                }
                
                if(node->right){
                    q.push(node->right);
                }
                
            }
            
            level++;
            
        }
        
        return level;
        
    }
    
    int maxDepth(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        
        int ht=depth2(root);
        
        return ht;
        
    }
};