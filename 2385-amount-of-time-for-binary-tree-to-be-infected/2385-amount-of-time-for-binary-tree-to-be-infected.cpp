class Solution {
public:
    
    void add_subtree(TreeNode* &root,int &maxTime,int timer){
        if(!root) return;
        maxTime = max(maxTime,timer);
        add_subtree(root->left,maxTime,timer + 1);
        add_subtree(root->right,maxTime,timer + 1);
    }
    
    int traverse(TreeNode* &root,int start,int &maxTime){
        if(!root) return -1;
        
        if(root->val == start){
            add_subtree(root,maxTime,0);
            return 1;
        }
        
        int dist = traverse(root->left,start,maxTime);
        
        if(dist > -1){
            maxTime = max(maxTime,dist);
            add_subtree(root->right,maxTime,dist + 1);
            return dist + 1;
        }
        
        dist = traverse(root->right,start,maxTime);
        
        if(dist > -1){
            maxTime = max(maxTime,dist);
            add_subtree(root->left,maxTime,dist + 1);
            return dist + 1;
        }
        
        return -1;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;
        int maxTime = 0;
        traverse(root,start,maxTime);
        return maxTime;
    }
};