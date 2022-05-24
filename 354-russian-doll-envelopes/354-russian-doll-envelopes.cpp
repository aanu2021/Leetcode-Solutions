class Solution {
public:
    
    bool static comp(vector<int>&x,vector<int>&y){
        
        if(x[0]==y[0]){
            return x[1] > y[1];
        }
        
        return x[0]<y[0];
        
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(),envelopes.end(),comp);
        
        vector<int>tails;
        
        tails.push_back(envelopes[0][1]);
        
        int n=envelopes.size();
        
        for(int i=1;i<n;i++){
            
            int curr=envelopes[i][1];
            
            if(tails.back()<curr){
                tails.push_back(curr);
            }
            
            else{
                int idx=lower_bound(tails.begin(),tails.end(),curr)-tails.begin();
                tails[idx]=curr;
            }
            
        }
        
        return tails.size();
        
    }
};