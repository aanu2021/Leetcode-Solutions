class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        if(!root){
            return {};
        }
        
        stack<pair<TreeNode*,int>>S;
        
        S.push({root,1});
        
        vector<int>preorder;
        vector<int>inorder;
        vector<int>postorder;
        
        
        while(!S.empty()){
            
            auto curr=S.top();
            S.pop();
            
            if(curr.second==1){
                
                curr.second++;
                
                preorder.push_back(curr.first->val);
                
                S.push(curr);
                
                if(curr.first->left){
                    
                    S.push({curr.first->left,1});
                    
                }
                
            }
            
            else if(curr.second==2){
                
                curr.second++;
                
                inorder.push_back(curr.first->val);
                
                S.push(curr);
                
                if(curr.first->right){
                    
                    S.push({curr.first->right,1});
                    
                }
                
            }
            
            else{
                
                postorder.push_back(curr.first->val);
                
            }
            
        }
        
        int n=preorder.size();
        
        for(int i=0;i<n;++i){
            
            cout<<preorder[i]<<" ";
            
        }cout<<"\n";
        
        for(int i=0;i<n;++i){
            
            cout<<inorder[i]<<" ";
            
        }cout<<"\n";
        
        for(int i=0;i<n;++i){
            
            cout<<postorder[i]<<" ";
            
        }cout<<"\n";
        
        return postorder;
        
        
        
    }
};