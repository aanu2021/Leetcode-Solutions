
class Solution {
public:
    
    vector<int>pre;
    
    void preorder(TreeNode*root){
        
        if(root==NULL){
            return;
        }
        
        pre.push_back(root->val);
        
        preorder(root->left);
        
        preorder(root->right);
        
    }
    
    void flatten(TreeNode* root) {
        
        if(root==NULL){
            return;
        }
        
        preorder(root);
        
        // for(int i=0;i<pre.size();++i){
        //     cout<<pre[i]<<" ";
        // }cout<<"\n";
        
        
        int idx=1;
        
        int n=pre.size();
        
        root->val=pre[0];
        
        while(idx<n){
            
            root->right=new TreeNode(pre[idx++]);
            
            root->left=NULL;
            
            root=root->right;
            
        }
        
    
        
    }
};