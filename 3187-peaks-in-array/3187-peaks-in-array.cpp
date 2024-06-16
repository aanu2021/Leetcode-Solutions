class Solution {
public:
    
    vector<int>tree;
    
    void update(int idx, int low, int high, int pos, int val){
        if(low > high) return;
        if(low == high){
            tree[idx] = val;
            return;
        }
        else{
            int mid = (low + high)/2;
            if(pos <= mid){
                update(2*idx+1, low, mid, pos, val);
            }
            else{
                update(2*idx+2, mid+1, high, pos, val);
            }
            tree[idx] = tree[2*idx+1] + tree[2*idx+2];
        }
    }
    
    int query(int idx, int low, int high, int l, int r){
        if(low > high || low > r || high < l) return 0;
        if(low == high) return tree[idx];
        if(low >= l && high <= r) return tree[idx];
        else{
            int mid = (low + high)/2;
            int leftQuery = query(2*idx+1, low, mid, l, r);
            int rightQuery = query(2*idx+2, mid+1, high, l, r);
            return leftQuery + rightQuery;
        }
    }
    
    bool isValidIndex(int index, int n){
        if(index < 0 || index >= n) return false;
        if(index-1 < 0 || index-1 >= n) return false;
        if(index+1 < 0 || index+1 >= n) return false;
        return true;
    }
    
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        tree.clear();
        tree = vector<int>(4*n+5, 0);
        
        for(int i=1;i<n-1;i++){
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]){
                update(0, 0, n-1, i, 1);
            }
        }
        
        int q = queries.size();
        vector<int>answer;
        
        for(int i=0;i<q;i++){
            int type = queries[i][0];
            if(type == 1){
                int l = queries[i][1];
                int r = queries[i][2];
                int sum = query(0, 0, n-1, l+1, r-1);
                answer.push_back(sum);
            }
            else{
                int idx = queries[i][1];
                int val = queries[i][2];
                update(0, 0, n-1, idx, 0);
                if(idx-1 >= 0) update(0, 0, n-1, idx-1, 0);
                if(idx+1 <  n) update(0, 0, n-1, idx+1, 0);
                nums[idx] = val;
                // cout<<idx<<"\n";
                // cout<<isValidIndex(idx, n)<<"\n";
                if(isValidIndex(idx, n)){
                    if(nums[idx] > nums[idx-1] && nums[idx] > nums[idx+1]){
                        update(0, 0, n-1, idx, 1);
                    }
                }
                if(isValidIndex(idx-1, n)){
                    if(nums[idx-1] > nums[idx-2] && nums[idx-1] > nums[idx]){
                        update(0, 0, n-1, idx-1, 1);
                    }
                }
                if(isValidIndex(idx+1, n)){
                    if(nums[idx+1] > nums[idx] && nums[idx+1] > nums[idx+2]){
                        update(0, 0, n-1, idx+1, 1);
                    }
                }
            }
        }
        return answer;
        
    }
};


// 4 1 4 2 1 5
// 0 1 2 3 4 5
// 0 0 1 0 0 0 
    
    
// 2 2 4
// 1 0 2
// 1 0 4
    
    