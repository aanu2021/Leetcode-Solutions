class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        if(n==1){
            return {{1}};
        }
        
        vector<vector<int>>result;
        
        result.push_back({1});
        
        for(int i=1;i<n;i++){
            
            vector<int>v(i+1);
            
            v[0]=result.back()[0];
            v[i]=result.back()[i-1];
            
            for(int j=1;j<i;j++){
                v[j]=result.back()[j-1]+result.back()[j];
            }
            
            result.push_back(v);
            
        }
        
        return result;
        
    }
};