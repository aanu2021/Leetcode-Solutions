class Solution {
public:
    
    vector<int>answer;
    
    void add_subtree(TreeNode* &root,int dist){
        if(!root || dist < 0) return;
        if(dist==0) answer.push_back(root->val);
        add_subtree(root->left,dist-1);
        add_subtree(root->right,dist-1);
    }
    
    int traverse(TreeNode* &root,TreeNode* &target,int k){
        if(!root) return -1;
        
        if(root->val == target->val){
            add_subtree(root,k);
            return k - 1;
        }
        
        int dist = traverse(root->left,target,k);
        
        if(dist > -1){
            if(dist==0) answer.push_back(root->val);
            add_subtree(root->right,dist-1);
            return dist - 1;
        }
        
        dist = traverse(root->right,target,k);
        
        if(dist > -1){
            if(dist==0) answer.push_back(root->val);
            add_subtree(root->left,dist-1);
            return dist - 1;
        }
        
        return -1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        answer.clear();
        traverse(root,target,k);
        return answer;
    }
};