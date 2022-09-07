class Solution {
public:
    string tree2str(TreeNode* root) {
        
        if(!root){
            return "";
        }
        
        stack<TreeNode*>S;
        
        set<TreeNode*>visited;
        
        S.push(root);
        
        string s="";
        
        while(!S.empty()){
            
            auto curr=S.top();
            
            if(visited.find(curr)!=visited.end()){
                
                S.pop();
                s+=")";
                
            }
            
            else{
                
                visited.insert(curr);
                
                s+="(";
                
                s+=to_string(curr->val);
                
                if(curr->left==NULL && curr->right!=NULL){
                    
                    s+="()";
                    
                }
                
                if(curr->right!=NULL){
                    
                    S.push(curr->right);
                    
                }
                
                if(curr->left!=NULL){
                    
                    S.push(curr->left);
                    
                }
                
            }
            
        }
        
        return s.substr(1,s.length()-2);
        
    }
};