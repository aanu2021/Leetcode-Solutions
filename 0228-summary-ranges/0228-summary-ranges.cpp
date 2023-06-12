class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
       vector<string>ans;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            
            int begin=nums[i];
            
            while(i<n-1 && nums[i]==nums[i+1]-1){
                i++;
            }
            
            int end=nums[i];
            
            if(begin==end){
                
                string s="";
                
                s+=to_string(begin);
                
                ans.push_back(s);
                
            }
            
            else{
                
                string s="";
                
                s+=to_string(begin);
                s+="->";
                s+=to_string(end);
                
                ans.push_back(s);
                
            }
            
        }
        
        return ans;
        
    }
};