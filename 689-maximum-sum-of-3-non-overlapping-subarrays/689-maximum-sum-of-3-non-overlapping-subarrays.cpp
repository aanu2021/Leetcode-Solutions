class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        vector<int>prefix(n,0);
        
        // Calculate the Sum of the middle K-length Subarray.........
        
        prefix[0]=nums[0];
        
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        
        // K-Length Subarray at the extreme left........
        
        vector<int>left(n,0);
        vector<int>leftidx(n,-1);
        
        
        // K-Length Subarray at the extreme right........
        
        vector<int>right(n,0);
        vector<int>rightidx(n,-1);
        
        
        int sum=0;
        
        
        
        for(int i=0;i<k;i++){
            sum+=nums[i];
            left[i]=sum;
            leftidx[i]=(i-k+1);
        }
        
        
        
        for(int i=k;i<n;i++){
            
            sum+=nums[i];
            sum-=nums[i-k];
            
            if(sum>left[i-1]){
                
                leftidx[i]=i-k+1;
                
            }
            
            else{
                
                leftidx[i]=leftidx[i-1];
                
            }
            
            left[i]=max(left[i-1],sum);
            
        }
        
        
        sum=0;
        
        for(int i=n-1;i>=n-k;i--){
            sum+=nums[i];
            right[i]=sum;
            rightidx[i]=i;
        }
        
        
        for(int i=n-k-1;i>=0;i--){
            
            sum+=nums[i];
            sum-=nums[i+k];
            
            if(sum>=right[i+1]){
                
                rightidx[i]=i;
                
            }
            
            else{
                
                rightidx[i]=rightidx[i+1];
                
            }
            
            right[i]=max(right[i+1],sum);
            
        }
        
        
        vector<int>result(3,-1);
        
        int maxval=0;
        
        // Traversing the initial index of the middle subarray.......
        
        for(int i=k;i<=n-k-k;i++){
            
            int currsum=left[i-1]+right[i+k];
            
            int midsum=prefix[i+k-1]-(i-1>=0 ? prefix[i-1] : 0);
            
            currsum+=midsum;
            
            if(currsum>maxval){
                
                maxval=currsum;
                
                result[0]=leftidx[i-1];
                result[1]=i;
                result[2]=rightidx[i+k];
                
            }
            
        }
        
        return result;
        
    }
};