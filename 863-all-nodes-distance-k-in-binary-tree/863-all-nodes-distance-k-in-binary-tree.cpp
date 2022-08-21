class Solution {
public:
    
    unordered_map<TreeNode*,TreeNode*>parent;
    
    void dfs(TreeNode*&root){
        
        if(!root){
            return;
        }
        
        if(root->left){
            
            parent[root->left]=root;
            
        }
        
        if(root->right){
            
            parent[root->right]=root;
            
        }
        
        dfs(root->left);
        dfs(root->right);
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        if(!root){
            return {};
        }
        
        dfs(root);
        
        queue<TreeNode*>q;
        
        unordered_set<TreeNode*>visited;
        
        vector<int>ans;
        
        q.push(target);
        
        int lvl=0;
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                auto node=q.front();
                q.pop();
                
                if(visited.find(node)!=visited.end()){
                    continue;
                }
                
                
                visited.insert(node);
                
                if(lvl==k){
                    ans.push_back(node->val);
                }
                
                if(parent.find(node)!=parent.end() && visited.find(parent[node])==visited.end()){
                    
                    q.push(parent[node]);
                    
                }
                
                if(node->left && visited.find(node->left)==visited.end()){
                    
                    q.push(node->left);
                    
                }
                
                 if(node->right && visited.find(node->right)==visited.end()){
                    
                    q.push(node->right);
                    
                }
                
            }
            
            
            lvl++;
            
            if(lvl>k){
                break;
            }
            
        }
        
        return ans;
        
    }
};