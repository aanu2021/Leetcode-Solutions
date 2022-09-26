class Solution {
public:
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        
        if(x[0] == y[0]){
            
            return x[1] > y[1];
            
        }
        
        return x[0] < y[0];
        
    }
    
    int maxEnvelopes(vector<vector<int>>& dimensions) {
        
        int n=dimensions.size();
        
        sort(dimensions.begin(),dimensions.end(),comp);
        
        vector<int>tails;
        
        tails.push_back(dimensions[0][1]);
        
        for(int i=1;i<n;++i){
            
            if(tails.back()<dimensions[i][1]){
                tails.push_back(dimensions[i][1]);
            }
            
            else{
                int idx=lower_bound(tails.begin(),tails.end(),dimensions[i][1])-tails.begin();
                tails[idx]=dimensions[i][1];
            }
            
        }
        
        return tails.size();
        
        
    }
};