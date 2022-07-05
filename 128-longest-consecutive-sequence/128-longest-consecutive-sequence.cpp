class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
     
        int n=nums.size();
        
        int maxLen=0;
        
        set<int>S;
        
        for(int i:nums){
            S.insert(i);
        }
        
        for(int num:S){
            
            if(S.find(num-1)==S.end()){
                
                int currnum=num;
                
                int currLen=1;
                
                while(S.find(currnum+1)!=S.end()){
                    
                    currnum++;
                    
                    currLen++;
                    
                }
                
                maxLen=max(maxLen,currLen);
                
            }
            
            else{
                
                continue;
                
            }
            
        }
        
        return maxLen;
        
    }
};