class Solution {
public:
    
    int seg[400005];
    
    void BuildSeg(int idx,int low,int high){
        
        if(low>high){
            return;
        }
        
        if(low==high){
            seg[idx]=0;
            return;
        }
        
        else{
            
            int mid=(low+high)/2;
            
            BuildSeg(2*idx+1,low,mid);
            BuildSeg(2*idx+2,mid+1,high);
            
            seg[idx]=0;
            
        }
        
    }
    
    void Update(int idx,int low,int high,int pos){
        
        if(low>high){
            return;
        }
        
        if(low==high){
            seg[idx]++;
            return;
        }
        
        else{
            
            int mid=(low+high)/2;
            
            if(pos<=mid){
                Update(2*idx+1,low,mid,pos);
            }else{
                Update(2*idx+2,mid+1,high,pos);
            }
            
            seg[idx]=seg[2*idx+1]+seg[2*idx+2];
            
        }
        
    }
    
    int query(int idx,int low,int high,int l,int r){
        
        if(low>high || low>r || high<l){
            return 0;
        }
        
        if(low==high){
            return seg[idx];
        }
        
        else if(low>=l && high<=r){
            return seg[idx];
        }
        
        else{
            
            int mid=(low+high)/2;
            
            int left=query(2*idx+1,low,mid,l,r);
            int right=query(2*idx+2,mid+1,high,l,r);
            
            return left+right;
            
        }
        
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        
        int n=nums.size();
        
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            nums[i]-=mini;
        }
        
        int m=maxi-mini;
        
        BuildSeg(0,0,m);
        
        vector<int>ans(n,0);
        
        for(int i=n-1;i>=0;i--){
            
            ans[i]=query(0,0,m,0,nums[i]-1);
            
            Update(0,0,m,nums[i]);
            
        }
        
        return ans;
        
    }
};