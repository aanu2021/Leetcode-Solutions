class Solution {
public:
    
    typedef long long ll;
    
    bool isPossible(vector<int>&nums,ll target){
        
        int n = nums.size();
        
        ll currsum = 0LL;
        
        for(int i=0;i<n;i++){
            
            if((ll)nums[i] < target){
                
                currsum += (target-nums[i]);
                
            }
            
            else if((ll)nums[i] > target){
                
                ll diff = nums[i] - target;
                
                if(currsum >= diff){
                    
                    currsum -= diff;
                    
                }
                
                else{
                    
                    return false;
                    
                }
                
            }
            
        }
        
        return true;
        
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        
        int n = nums.size();
        
        ll sum = 0LL;
        
        ll maxi = 0LL;
        
        for(int i=0;i<n;i++){
            
            sum+=(ll)nums[i];
            
            ll curr = (sum/(i+1));
            
            if(sum%(i+1)) curr++;
            
            maxi = max(maxi,curr);
            
        }
        
        return maxi;
        
    }
};

//               13 , 13 , 20 , 0 , 8 , 9 , 9
    
// target = 16   
                  
//               13 , 13 ,     