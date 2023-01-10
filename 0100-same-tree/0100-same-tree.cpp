class Solution {
public:
    bool isSameTreeBFS(TreeNode* p, TreeNode* q) {
        
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        
        queue<TreeNode*>q1,q2;
        q1.push(p); q2.push(q);
        
        while(!q1.empty() || !q2.empty()){
            
            auto node1 = q1.front(); q1.pop();
            auto node2 = q2.front(); q2.pop();
            
            if(node1==NULL && node2==NULL) continue;
            if(node1==NULL || node2==NULL) return false;
            if(node1->val != node2->val) return false;
            
            q1.push(node1->left);
            q1.push(node1->right);
            
            q2.push(node2->left);
            q2.push(node2->right);
            
        }
        return true;
    }
    
    bool isSameTreeDFS(TreeNode* p, TreeNode* q) {
        
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        
        queue<TreeNode*>q1,q2;
        q1.push(p); q2.push(q);
        
        while(!q1.empty() || !q2.empty()){
            
            auto node1 = q1.front(); q1.pop();
            auto node2 = q2.front(); q2.pop();
            
            if(node1==NULL && node2==NULL) continue;
            if(node1==NULL || node2==NULL) return false;
            if(node1->val != node2->val) return false;
            
            q1.push(node1->left);
            q1.push(node1->right);
            
            q2.push(node2->left);
            q2.push(node2->right);
            
        }
        return true;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        return isSameTreeBFS(p,q);
        
    }
    
};