class Solution {
public:
    
    vector<int>levelSum;
    
    void dfs(TreeNode* &root,int lvl){
        
        if(!root) return;
        
        if(levelSum.size() < lvl){
            levelSum.push_back(root->val);
        }else{
            levelSum[lvl-1] += root->val;
        }
        
        dfs(root->left,lvl+1);
        dfs(root->right,lvl+1);
        
    }
    
    int maxLevelSum(TreeNode* root) {
        
        if(!root) return -1;
        
        levelSum.clear();
        
        dfs(root,1);
        
        int maxSum = *max_element(levelSum.begin(),levelSum.end());
        
        for(int i=0;i<levelSum.size();i++){
            if(levelSum[i] == maxSum){
                return i+1;
            }
        }
        
        return -1;
        
    }
};