class Solution {
public:
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        
        if(x[0]==y[0]){
            
            return x[1] > y[1];
            
        }
        
        return x[0] < y[0];
        
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
        int n=properties.size();
        
        sort(properties.begin(),properties.end(),comp);
        
        int maxi=-1;
        
        int ans=0;
        
        for(int i=n-1;i>=0;i--){
            
            if(properties[i][1] < maxi){
                
                ans++;
                
            }
            
            maxi=max(maxi,properties[i][1]);
            
        }
        
        return ans;
        
    }
};