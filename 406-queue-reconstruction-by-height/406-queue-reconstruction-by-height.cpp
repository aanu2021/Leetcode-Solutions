class Solution {
public:
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        
        if(x[0]==y[0]){
            return x[1] < y[1];
        }
        
        return x[0] > y[0];
        
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
        
        sort(p.begin(),p.end(),comp);
        
        vector<vector<int>>ans;
        
        ans.push_back(p[0]);
        
        for(int i=1;i<p.size();++i){
            
            ans.insert(ans.begin()+p[i][1],p[i]);
            
        }
        
        return ans;
        
    }
};