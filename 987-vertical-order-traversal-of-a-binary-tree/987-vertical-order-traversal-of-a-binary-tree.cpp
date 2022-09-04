
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,vector<int>>mp;
        
        queue<pair<TreeNode*,int>>q;
        
        q.push({root,0});
        
        while(!q.empty()){
            
            int sz=q.size();
            
            map<int,vector<int>>currmp;
            
            while(sz--){
                
                auto curr=q.front();
                q.pop();
                
                auto node=curr.first;
                int val=curr.second;
                
                currmp[val].push_back(node->val);
                
                if(node->left){
                    
                    q.push({node->left,val-1});
                    
                }
                
                if(node->right){
                    
                    q.push({node->right,val+1});
                    
                }
                
            }
            
            for(auto &itr:currmp){
                
              sort(itr.second.begin(),itr.second.end());
                
            }
            
            for(auto itr:currmp){
                
                for(auto it:itr.second){
                    
                    mp[itr.first].push_back(it);
                    
                }
                
            }
            
        }
        
        vector<vector<int>>vec;
        
        for(auto itr:mp){
            
            vec.push_back(itr.second);
            
        }
        
        return vec;
        
    }
};