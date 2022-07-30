class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        
        vector<pair<int,int>>vec;
        
        for(int i=0;i<n;++i){
            vec.push_back({nums[i],i});
        }
        
        sort(vec.begin(),vec.end());
        
        int i=0,j=n-1;
        
        while(i<j){
            
            int currsum=vec[i].first+vec[j].first;
            
            if(currsum==target){
                return {vec[i].second,vec[j].second};
            }
            
            else if(currsum>target){
                j--;
            }
            
            else{
                i++;
            }
            
        }
        
        return {-1,-1};
        
    }
};