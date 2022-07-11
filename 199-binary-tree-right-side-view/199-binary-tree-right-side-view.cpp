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
    
    int dist[105];
    
    void func(TreeNode*root,int lvl){
        
        if(root==NULL){
            return;
        }
        
        dist[lvl]=root->val;
        
        func(root->left,lvl+1);
        
        func(root->right,lvl+1);
        
    }
    
    vector<int> rightSideView(TreeNode* root) {
        
        if(root==NULL){
            return {};
        }
        
        for(int i=0;i<=102;i++){
            dist[i]=-1;
        }
        
        func(root,1);
        
        vector<int>ans;
        
        // for(int i=1;i<=6;i++){
        //     cout<<dist[i]<<" ";
        // }cout<<"\n";
     
        for(int i=1;i<=102;++i){
            
            if(dist[i]==-1){
                break;
            }
            
            ans.push_back(dist[i]);
            
        }
        
        return ans;
        
    }
};