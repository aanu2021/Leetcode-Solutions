/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<TreeNode*>vec;
    unordered_set<TreeNode*>leaf;
    unordered_map<TreeNode*,TreeNode*>parent;
    
    void dfs(TreeNode*&root){
        if(!root) return;
        if(!root->left && !root->right){
            vec.push_back(root);
            leaf.insert(root);
            return;
        }else{
            if(root->left) parent[root->left] = root;
            if(root->right) parent[root->right] = root;
            dfs(root->left);
            dfs(root->right);
        }
    }
    
    int COUNT(TreeNode*&root,int distance){
        unordered_set<TreeNode*>visited;
        queue<TreeNode*>q;
        q.push(root);
        int lvl = 0;
        visited.insert(root);
        int cnt = 0;
        while(!q.empty() && lvl <= distance){
            int sz = q.size();
            while(sz--){
                auto node = q.front(); q.pop();
                if(node != root && leaf.find(node) != leaf.end()){
                    cnt++;
                }
                if(parent.find(node) != parent.end() && visited.find(parent[node]) == visited.end()){
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
                if(node->left && visited.find(node->left) == visited.end()){
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right && visited.find(node->right) == visited.end()){
                    q.push(node->right);
                    visited.insert(node->right);
                }
            }
            lvl++;
        }
        return cnt;
    }
    
    int countPairs(TreeNode* root, int distance) {
        
        if(!root) return 0;
        
        dfs(root);
        
        int sz = vec.size();
        int answer = 0;
       // cout<<sz<<"\n";
        
        for(int i=0;i<sz;i++){
            answer += COUNT(vec[i],distance);    
        }
        
        answer/=2;
        return answer;
        
    }
};