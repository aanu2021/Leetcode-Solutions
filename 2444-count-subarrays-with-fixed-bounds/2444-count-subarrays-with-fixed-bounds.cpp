class Solution {
public:
    
    typedef long long ll;
    
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        ll ans = 0LL;
        
        int n = nums.size();
        
        if(minK==maxK){
            
            for(int i=0;i<n;i++){
                
                if(nums[i]!=maxK) continue;
                
                int j = i;
                
                ll cnt = 0;
                
                while(j<n && nums[j]==nums[i]){
                    
                    cnt++;
                    j++;
                    
                }
                
                ans += ((cnt*(cnt+1))/2);
                
                i=j;
                i--;
                
            }
            
            return ans;
            
        }
        
        vector<int>obstacle(n,n);
        
        vector<int>minarr(n,n+5);
        
        vector<int>maxarr(n,n+5);
        
        if(nums[n-1]==minK){
            minarr[n-1]=n-1;
        }
        
        else if(nums[n-1]==maxK){
            maxarr[n-1]=n-1;
        }
        
        else if(nums[n-1] < minK || nums[n-1] > maxK){
            obstacle[n-1]=n-1;
        }
        
        for(int i=n-2;i>=0;i--){
            
            if(nums[i]==minK){
                minarr[i]=i;
                maxarr[i]=maxarr[i+1];
                obstacle[i]=obstacle[i+1];
            }
            
            else if(nums[i]==maxK){
                maxarr[i]=i;
                minarr[i]=minarr[i+1];
                obstacle[i]=obstacle[i+1];
            }
            
            else if(nums[i] < minK || nums[i] > maxK){
                maxarr[i]=n+5;
                minarr[i]=n+5;
                obstacle[i]=i;
            }
            
            else{
                obstacle[i]=obstacle[i+1];
                minarr[i]=minarr[i+1];
                maxarr[i]=maxarr[i+1];
            }
            
        }
        
        for(int i=0;i<n;i++){
            
            if(nums[i] < minK || nums[i] > maxK) continue;
            
            if(nums[i]==minK){
                
                ll maxr = maxarr[i];
                ll obsr = obstacle[i];
                
                ll curr = max(0LL,obsr-maxr);
                
                ans += curr;
                
            }
            
            else if(nums[i]==maxK){
                
                ll minr = minarr[i];
                ll obsr = obstacle[i];
                
                ll curr = max(0LL,obsr-minr);
                
                ans += curr;
                
            }
            
            else{
                
                ll minr = minarr[i];
                ll maxr = maxarr[i];
                ll obsr = obstacle[i];
                
                ll curr = max(0LL,obsr-max(minr,maxr));
                
                ans += curr;
                
            }
            
        }
        
        return ans;
        
    }
};