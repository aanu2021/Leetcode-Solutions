class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        vector<pair<int,int>>vec;
        
        for(int i=0;i<nums.size();++i){
            
            for(int j=0;j<nums[i].size();++j){
                
                vec.push_back({nums[i][j],i});
                
            }
            
        }
        
        sort(vec.begin(),vec.end());
        
        int n=vec.size();
        
        int k=nums.size();
        
        unordered_map<int,int>freq;
        
        int l=0,r=0;
        
        int count=0;
        
        int minLen=1e9;
        
        int left_val=-1,right_val=-1;
        
        
        while(r<n){
            
            if(freq[vec[r].second]==0){
                count++;
            }
            
            freq[vec[r].second]++;
            
            while(l<=r && count==k){
                
                int currLen=(vec[r].first-vec[l].first+1);
                
                if(currLen < minLen){
                    
                    minLen=currLen;
                    
                    left_val=vec[l].first;
                    right_val=vec[r].first;
                    
                }
                
                freq[vec[l].second]--;
                
                if(freq[vec[l].second]==0){
                    
                    count--;
                    
                }
                
                l++;
                
            }
            
            r++;
            
        }
        
        return {left_val,right_val};
        
    }
};
