class Solution {
public:
    
    multiset<int,greater<int>>ms;
    
    int ans=0;
    
    void func(TreeNode*root){
        
        if(root==NULL){
            return;
        }
        
        ms.insert(root->val);
        
        int maxval_root_to_node=*ms.begin();
        
        if(maxval_root_to_node<=root->val){
            
            ans++;
            
        }
        
        if(root->left){
            
            func(root->left);
            
        }
        
        if(root->right){
            
            func(root->right);
            
        }
        
        ms.erase(ms.lower_bound(root->val));
        
    }
    
    int goodNodes(TreeNode* root) {
        
//         value<=node.val ----- (1)
            
//  Max Value across the path from root to node <= node.val ---(2)      
          func(root);   
        
          return ans;
            
    }
};