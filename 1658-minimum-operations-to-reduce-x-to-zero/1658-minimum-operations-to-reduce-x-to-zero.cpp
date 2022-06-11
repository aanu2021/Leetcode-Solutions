class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n=nums.size();
        
        int sum=accumulate(nums.begin(),nums.end(),0);
        
        if(sum==x){
            return n;
        }
        
        int target=sum-x;
        
        int maxLen=-1;
        
        map<int,int>mp;
        
        int currsum=0;
        
        mp[0]=-1;
        
        // cout<<sum<<endl;
        
        for(int i=0;i<n;i++){
            
            currsum+=nums[i];
            
           // cout<<currsum<<endl;
            
            if(mp.find(currsum-target)!=mp.end()){
                maxLen=max(maxLen,i-mp[currsum-target]);
            }
            
            if(mp.find(currsum)==mp.end()){
                mp[currsum]=i;
            }
            
           // cout<<maxLen<<" ";
            
        }
        
        
        
        if(maxLen==-1){
            return -1;
        }
        
        else{
            return n-maxLen;
        }
        
    }
};