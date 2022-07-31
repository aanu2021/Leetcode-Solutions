class NumArray {
public:
    
    int n;
    int tree[400005];
    int arr[100005];
    
   void BuildSeg(int idx,int low,int high){
        
        if(low>high){
            return;
        }
        
        if(low==high){
            tree[idx]=arr[low];
            return;
        }
        
        else{
            
            int mid=(low+high)/2;
            
            BuildSeg(2*idx+1,low,mid);
            BuildSeg(2*idx+2,mid+1,high);
            
            tree[idx]=tree[2*idx+1]+tree[2*idx+2];
            
        }
        
    }
    
    void Update(int idx,int low,int high,int pos,int val){
        
        if(low>high){
            return;
        }
        
        if(low==high){
            tree[idx]=val;
            arr[pos]=val;
            return;
        }
        
        else{
            
            int mid=(low+high)/2;
            
            if(pos<=mid){
                Update(2*idx+1,low,mid,pos,val);
            }else{
                Update(2*idx+2,mid+1,high,pos,val);
            }
            
            tree[idx]=tree[2*idx+1]+tree[2*idx+2];
            
        }
        
    }
    
    int query(int idx,int low,int high,int l,int r){
        
        if(low>high || low>r || high<l){
            return 0;
        }
        
        if(low==high){
            return tree[idx];
        }
        
        else if(low>=l && high<=r){
            return tree[idx];
        }
        
        else{
            
            int mid=(low+high)/2;
            
            int left=query(2*idx+1,low,mid,l,r);
            int right=query(2*idx+2,mid+1,high,l,r);
            
            return left+right;
            
        }
        
    }
    
    NumArray(vector<int>& nums) {
        
        n=nums.size();
        
        for(int i=0;i<n;++i){
            arr[i]=nums[i];
        }
        
        BuildSeg(0,0,n-1);
        
    }
    
    void update(int index, int val) {
        
        Update(0,0,n-1,index,val);
        
    }
    
    int sumRange(int left, int right) {
       
        return query(0,0,n-1,left,right);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */