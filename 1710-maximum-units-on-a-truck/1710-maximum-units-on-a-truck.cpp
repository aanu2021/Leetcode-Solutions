class Solution {
public:
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        
        return x[1] > y[1];
        
    }
    
    int maximumUnits(vector<vector<int>>& v, int k) {
        
        int n=v.size();
        
        sort(v.begin(),v.end(),comp);
        
        int ans=0;
        
        for(int i=0;i<v.size();++i){
            
            int currbox=v[i][0];
            
            int unit=v[i][1];
            
            
            if(k>=currbox){
                
                ans+=(currbox*unit);
                
                k-=currbox;
                
            }
            
            else{
                
                ans+=(k*unit);
                
                break;
                
            }
            
        }
        
        return ans;
        
    }
};