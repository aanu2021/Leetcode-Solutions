class Solution {
public:
    
    unordered_map<TreeNode*,TreeNode*>parent;
    
    unordered_map<TreeNode*,bool>visited;
    
    void dfs(TreeNode*&root){
        
        if(root==NULL){
            return;
        }
        
        if(root->left!=NULL){
            
            parent[root->left]=root;
            
        }
        
        if(root->right!=NULL){
            
            parent[root->right]=root;
            
        }
        
        dfs(root->left);
        
        dfs(root->right);
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int>ans;
        
        int level=0;
        
        dfs(root);
        
        queue<TreeNode*>q;
        
        q.push(target);
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                auto curr=q.front();
                q.pop();
                
                if(visited[curr]==true){
                    
                    continue;
                    
                }
                
                visited[curr] = true;
                
                if(level==k){
                    
                    ans.push_back(curr->val);
                    continue;
                    
                }
                
                if(parent.find(curr)!=parent.end()){
                    
           //  cout<<curr->val<<" "<<parent[curr]->val<<"\n";
                    
                    q.push(parent[curr]);
                    
                }
                
                if(curr->left!=NULL){
                    
                    q.push(curr->left);
                    
                }
                
                if(curr->right!=NULL){
                    
                    q.push(curr->right);
                    
                }
                
            }
            
            level++;
            
        }
        
        return ans;
        
    }
};