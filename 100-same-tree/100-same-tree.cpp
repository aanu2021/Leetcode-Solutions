class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
       if(p==NULL && q==NULL){
           return true;
       }
        
       if(p==NULL || q==NULL){
           return false;
       } 
        
       queue<TreeNode*>queue_p;
       queue<TreeNode*>queue_q;
        
       queue_p.push(p);
       queue_q.push(q);
        
       while(!queue_p.empty() || !queue_q.empty()){
           
           auto curr_p=queue_p.front();
           queue_p.pop();
           
           auto curr_q=queue_q.front();
           queue_q.pop();
           
           if(curr_p==NULL && curr_q==NULL){
               continue;
           }
           
           if(curr_p==NULL || curr_q==NULL){
               return false;
           }
           
           if(curr_p->val!=curr_q->val){
               return false;
           }
           
           if(curr_p){
               
               queue_p.push(curr_p->left);
               queue_p.push(curr_p->right);
               
           }
           
           if(curr_q){
               
               queue_q.push(curr_q->left);
               queue_q.push(curr_q->right);
               
           }
           
       } 
        
       return true; 
        
    }
};