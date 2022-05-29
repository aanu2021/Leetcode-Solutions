class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int n=words.size();
        
        vector<pair<int,int>>vec(n);
        
        for(int i=0;i<n;i++){
            
            int mask=0;
            
            for(int j=0;j<words[i].length();j++){
                
                mask|=(1<<words[i][j]-'a');
                
            }
            
            vec[i]={words[i].length(),mask};
            
        }
        
        int maxLen=0;
        
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
                
                int mask1=vec[i].second;
                int mask2=vec[j].second;
                
                if((mask1&mask2)==0){
                    maxLen=max(maxLen,(vec[i].first*vec[j].first));
                }
                
            }
            
        }
        
        return maxLen;
        
    }
};