class Solution {
public:
    
    bool static comp(const pair<int,int>&x,const pair<int,int>&y)
    {
        
        return x.second > y.second;
        
    }    
        
    
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        int n = plantTime.size();
        
        vector<pair<int,int>>vec(n);
        
        for(int i=0;i<n;i++){
            vec[i]={plantTime[i],growTime[i]};
        }
        
        sort(vec.begin(),vec.end(),comp);
        
        int start = 0; // Day after which we will start the next plantation.
        
        int end = 0; // Maximum (plant + growth) Time will be the answer out of all possible flowers.
        
        for(int i=0;i<n;i++){
            
            start += vec[i].first;
            end = max(end,start+vec[i].second);
            
        }
        
        return end;
        
    }
};

    