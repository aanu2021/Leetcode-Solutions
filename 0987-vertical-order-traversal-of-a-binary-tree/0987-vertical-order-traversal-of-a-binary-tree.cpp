class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>answer;
        if(!root) return {};
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        map<int,vector<int>>Map;
        while(!q.empty()){
            int sz = q.size();
            unordered_map<int,vector<int>>mp;
            while(sz--){
                auto curr = q.front(); q.pop();
                auto node = curr.first;
                int hd = curr.second;
                mp[hd].push_back(node->val);
                if(node->left){
                    q.push({node->left, hd-1});
                }
                if(node->right){
                    q.push({node->right, hd+1});
                }
            }
            for(auto &itr : mp){
                sort(itr.second.begin(),itr.second.end());
            }
            for(auto &itr : mp){
                for(auto &it : itr.second){
                    Map[itr.first].push_back(it);
                }
            }
        }
        for(auto &itr : Map){
            vector<int>temp;
            for(auto &it : itr.second){
                temp.push_back(it);
            }
            answer.push_back(temp);
        }
        return answer;
    }
};