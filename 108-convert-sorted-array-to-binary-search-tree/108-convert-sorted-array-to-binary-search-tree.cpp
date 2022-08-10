
class Solution {
public:
    
    struct Node{
      
        int low;
        int high;
        TreeNode*node;
        
        Node(int l,int h,TreeNode*n){
            
            low=l;
            high=h;
            node=n;
            
        }
        
    };
    
    int getMid(int low,int high){
        
        return ((low+high)/2);
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==0){
            return NULL;
        }
        
        
        int midIndex=getMid(0,n-1);
        
        TreeNode*root=new TreeNode(nums[midIndex]);
        
        
        stack<Node>S;
        
        S.push({0,n-1,root});
        
        
        while(!S.empty()){
            
            auto curr_entity=S.top();
            S.pop();
            
            int low       = curr_entity.low;
            int high      = curr_entity.high;
            TreeNode*node = curr_entity.node;
            
            midIndex=getMid(low,high);
            
            if(midIndex-1>=low){
                
            int midIndex_for_left_sub=getMid(low,midIndex-1);
                
        node->left=new TreeNode(nums[midIndex_for_left_sub]);
                
                S.push({low,midIndex-1,node->left});
                
            }
            
            if(midIndex+1<=high){
                
                int midIndex_for_right_sub=getMid(midIndex+1,high);
                
        node->right=new TreeNode(nums[midIndex_for_right_sub]);
                
                S.push({midIndex+1,high,node->right});
                
            }
            
        }
        
        return root;
        
    }
};