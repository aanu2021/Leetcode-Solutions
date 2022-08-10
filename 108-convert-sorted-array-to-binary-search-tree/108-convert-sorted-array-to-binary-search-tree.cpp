class Solution {
public:
    
    TreeNode*BuildBST(vector<int>&nums,int low,int high){
        
        if(low>high){
            return NULL;
        }
        
        int mid=(low+high)/2;
        
        TreeNode*root=new TreeNode(nums[mid]);
        
        root->left =BuildBST(nums,low,mid-1);
        root->right=BuildBST(nums,mid+1,high);
        
        return root;
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
      int n=nums.size();
        
        TreeNode*root=BuildBST(nums,0,n-1);
        
        return root;
        
    }
};