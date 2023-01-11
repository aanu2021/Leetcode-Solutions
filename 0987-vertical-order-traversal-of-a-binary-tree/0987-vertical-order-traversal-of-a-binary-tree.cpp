class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        map<int,vector<int>>globalIndex;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int sz = q.size();
            unordered_map<int,vector<int>>currIndex;
            while(sz--){
                auto curr = q.front();
                q.pop();
                auto node = curr.first;
                int col = curr.second;
                currIndex[col].push_back(node->val);
                if(node->left){
                    q.push({node->left,col-1});
                }
                if(node->right){
                    q.push({node->right,col+1});
                }
            }
            
            for(auto &itr:currIndex){
                sort(itr.second.begin(),itr.second.end());
            }
            
            for(auto &itr:currIndex){
                for(auto &ele:itr.second){
                    globalIndex[itr.first].push_back(ele);
                }
            }
        }
        
        vector<vector<int>>ans;
        for(auto &itr:globalIndex){
            vector<int>v;
            for(auto &ele:itr.second){
                v.push_back(ele);
            }
            ans.push_back(v);
        }
        return ans;
    }
};