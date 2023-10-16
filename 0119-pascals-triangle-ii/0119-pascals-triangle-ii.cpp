class Solution {
public:
    vector<int> getRow(int n) {
        
        vector<vector<int>>result;
        
        for(int i=0;i<=n;i++){
            
            vector<int>vec;
            
            for(int j=0;j<=i;j++){
                
                if(j==0 || j==i){
                    vec.push_back(1);
                }
                
                else{
                    vec.push_back(result[i-1][j-1]+result[i-1][j]);
                }
                
            }
            
            result.push_back(vec);
            
        }
        
        return result[n];
        
    }
};